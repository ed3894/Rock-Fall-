#include <Arduino_LSM9DS1.h>          // Library for onboard accelerometer
#include <rockfallmodel_inferencing.h> // Include the Edge Impulse model header

/** Data buffer for inference */
typedef struct {
    int16_t *buffer;  // Buffer to store data
    uint8_t buf_ready;
    uint32_t buf_count;
    uint32_t n_samples;
} inference_t;

static inference_t inference;
static bool debug_nn = false;         // Set to true to debug model features

// Function prototypes
static bool accelerometer_inference_start(uint32_t n_samples);
static bool accelerometer_inference_record(void);
static int accelerometer_signal_get_data(size_t offset, size_t length, float *out_ptr);

void setup() {
    Serial.begin(115200);
    while (!Serial);
    Serial.println("Edge Impulse Rockfall Detection");

    // Initialize accelerometer
    if (!IMU.begin()) {
        Serial.println("Failed to initialize IMU!");
        while (1);
    }
    Serial.println("IMU initialized!");

    // Initialize inference buffer
    if (!accelerometer_inference_start(EI_CLASSIFIER_RAW_SAMPLE_COUNT)) {
        ei_printf("ERR: Could not allocate inference buffer.\n");
        return;
    }

    // Initialize external LED on pin 11
    pinMode(11, OUTPUT);
    digitalWrite(11, LOW); // Ensure LED starts off
}

void loop() {
    ei_printf("Recording accelerometer data...\n");

    if (!accelerometer_inference_record()) {
        ei_printf("ERR: Failed to record data...\n");
        return;
    }

    ei_printf("Recording complete. Running inference...\n");

    signal_t signal;
    signal.total_length = EI_CLASSIFIER_RAW_SAMPLE_COUNT;
    signal.get_data = &accelerometer_signal_get_data;

    ei_impulse_result_t result = { 0 };

    EI_IMPULSE_ERROR r = run_classifier(&signal, &result, debug_nn);
    if (r != EI_IMPULSE_OK) {
        ei_printf("ERR: Failed to run classifier (%d)\n", r);
        return;
    }

    // Print predictions
    ei_printf("Predictions:\n");
    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        ei_printf("    %s: %.5f\n", result.classification[ix].label, result.classification[ix].value);
    }

    // Trigger the external LED based on rockfall detection
    if (result.classification[1].value > 0.95) { // Assuming class 0 is "rockfall"
        digitalWrite(11, HIGH);       // Turn on external LED
        ei_printf("Rockfall detected! Alert triggered. External LED ON.\n");
    } else {
        digitalWrite(11, LOW);        // Turn off external LED
        ei_printf("No rockfall detected. External LED OFF.\n");
    }

    delay(2000); // Delay before the next cycle
}

/**
 * @brief Initialize inference struct and allocate buffer
 * @param n_samples Number of samples for inference
 * @return True if initialization was successful
 */
static bool accelerometer_inference_start(uint32_t n_samples) {
    inference.buffer = (int16_t *)malloc(n_samples * sizeof(int16_t));
    if (inference.buffer == NULL) {
        return false;
    }
    inference.buf_count = 0;
    inference.n_samples = n_samples;
    inference.buf_ready = 0;
    return true;
}

/**
 * @brief Record accelerometer data
 * @return True when buffer is filled
 */
static bool accelerometer_inference_record(void) {
    inference.buf_ready = 0;
    inference.buf_count = 0;

    while (inference.buf_ready == 0) {
        if (IMU.accelerationAvailable()) {
            float x, y, z;
            IMU.readAcceleration(x, y, z);

            // Store only one axis (e.g., x-axis) in the buffer, scaled to int16
            inference.buffer[inference.buf_count++] = (int16_t)(x * 1000);

            if (inference.buf_count >= inference.n_samples) {
                inference.buf_ready = 1;
            }
        }
        delay(10);
    }
    return true;
}

/**
 * @brief Get accelerometer data as a signal
 * @param offset Offset in the buffer
 * @param length Number of elements to fetch
 * @param out_ptr Pointer to output array
 * @return 0 on success
 */
static int accelerometer_signal_get_data(size_t offset, size_t length, float *out_ptr) {
    numpy::int16_to_float(&inference.buffer[offset], out_ptr, length);
    return 0;
}
