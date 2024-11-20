# Overview

## Title
Embedded Rockfall Detection System Using TinyML with Real-Time, 3-Component Accelerometer and Gyroscope Data 

## Authors
1. Ahmed, Ahmed 
2. Deal, Ethan 
3. Ding, Yidan 

## Abstract

This project focuses on developing a lightweight, embedded system for real-time rockfall detection using an Arduino 33 BLE sensor equipped with a TinyML shield. A three-axis accelerometer and gyroscope were used to record vibrations caused by simulated rockfalls in a soil-filled bin inclined at 45°. The dataset consisted of 100 rockfall events and 100 background noise events, each sampled for 1.5 seconds at 100 Hz. An 80/20 training/testing split was applied, and spectral features were extracted using FFT preprocessing. A neural network with a 78-feature input layer, two dense layers (20 and 10 neurons), and a binary output layer was trained and tested, achieving an accuracy of 96.67% on the testing data. The model was deployed to the Arduino board, housed in a custom 3D-printed enclosure. A red LED flashes when rockfall events are detected, showcasing a real-time implementation of the model. Future work includes field validation, expanding datasets, and testing in varied environmental conditions for improved robustness and applicability.

## Introduction

## Overall Implementation and Design

# Quality Control

## Safety

## Calibration

## General Testing

# Application

## Use Cases

# Build Details

## Availability of Materials and Methods
[TinyML Shield](https://store-usa.arduino.cc/products/arduino-tiny-machine-learning-kit?srsltid=AfmBOoojrt-4hQ4G9KjtIXiajwsGtXGNaIXXYTDAT1c_LlG9_NxYmcPi)


## Ease of Build / Design Decision

## Operating Software and Peripherals

## Dependencies

## Hardware Documentation / Build Instructions / Files Location

# Discussion

## Conclusions

## Future Work

## Author Contributions

## Acknowledgments

## References


