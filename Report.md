# 1. Overview
## Title
Embedded Rockfall Detection System Using TinyML with Real-Time, 3-Component Accelerometer and Gyroscope Data 

## Authors
1. Ahmed, Ahmed 
2. Deal, Ethan 
3. Ding, Yidan 

## Abstract

This project focuses on developing a lightweight, embedded system for real-time rockfall detection using an Arduino 33 BLE sensor equipped with a TinyML shield. A three-axis accelerometer and gyroscope were used to record vibrations caused by simulated rockfalls in a soil-filled bin inclined at 45°. The dataset consisted of 100 rockfall events and 100 background noise events, each sampled for 1.5 seconds at 100 Hz. An 80/20 training/testing split was applied, and spectral features were extracted using FFT preprocessing. A neural network with a 78-feature input layer, two dense layers (20 and 10 neurons), and a binary output layer was trained and tested, achieving an accuracy of 96.67% on the testing data. The model was deployed to the Arduino board, housed in a custom 3D-printed enclosure. A red LED flashes when rockfall events are detected, showcasing a real-time implementation of the model. Future work includes field validation, expanding datasets, and testing in varied environmental conditions for improved robustness and applicability.

## Metadata Overview
Please provide the following overview and self-assessment 
Main design files: link to repository with design files and assembly instructions 
Target group: e.g. secondary school students, layperson, undergraduate students, scientists in [discipline], trained engineers, use of professional services 
Skills required: For each main manufacturing method, provide information pairs (method - easy / advanced / specialist). E.g. desktop 3d printing - easy; surface mount PCB - advanced; injection moulding - specialist 
Replication: Project has been replicated at time of publication? Include reference (possibly way of contact). Links to places where future builds and kits might be found (repository, group website, collaboration site, etc.). 
See section “Build Details” for more detail. 

## Keywords
TinyML; Rockfall Detection; Accelerometer; Edge Impulse; Real-Time Monitoring

## Introduction
Rockfalls are significant natural hazards in mountainous regions, often causing extensive damage and posing risks to human life and infrastructure. For instance, in November 2004, a major rockfall of approximately 1,500 cubic yards caused significant damage to Interstate-70 at mile-marker 125 in Glenwood Canyon, Colorado. Traditional methods for detecting and monitoring rockfalls, such as visual inspections and seismic monitoring, have various limitations, including high operational costs and poor real-time capabilities. Visual inspections, while essential, are subjective and heavily dependent on the expertise and perspective of the observer. Seismic monitoring, on the other hand, provides valuable data but can be complex and costly to maintain over large areas. Terrestrial Laser Scanning (TLS) has emerged as one of the most advanced techniques for monitoring and analyzing rockfalls due to its ability to produce high-resolution, accurate digital terrain models, which are crucial for evaluating rockfall trajectories and characteristics. This method has proven effective in identifying and quantifying rockfalls, allowing for better prediction and mitigation strategies ESurf. Also, Photogrammetry, specifically Structure-from-Motion (SfM), has been utilized to monitor rockfalls by creating detailed 3D models from photographs. This method is particularly useful for documenting rockfall occurrences over long periods and assessing changes in rockfall frequency and volume U.S. Geological Survey. Fiber optic sensing, another innovative approach, utilizes Distributed Acoustic Sensing (DAS) systems that can detect and locate rockfalls along linear infrastructures. These systems analyze the acoustic signals transmitted through fiber optic cables to pinpoint rockfall events, offering a real-time monitoring solution that complements other detection methods ESurf.

Recent advancements in machine learning, particularly the use of Tiny Machine Learning (TinyML) on low-power devices, offer new possibilities for enhancing rockfall detection systems. These intelligent frameworks integrate various machine learning models to handle real-time data efficiently, providing timely responses to potential rockfall events. This approach promises significant improvements over traditional methods by lowering costs, reducing energy consumption, and increasing the scalability of rockfall monitoring systems ar5iv. The integration of TinyML with sensors such as accelerometers and gyroscopes allow for the development of compact, efficient systems capable of detecting rockfalls in real-time. This technology not only streamlines the process of monitoring rock slopes but also enhances the safety measures by providing immediate data directly from the affected areas. By leveraging these advanced technologies, it is possible to develop more reliable, efficient, and cost-effective solutions for rockfall monitoring, which is essential for enhancing safety measures and reducing the risk to human lives and infrastructure. This manuscript will delve into the implementation of such a system, highlighting its design, operational benefits, and the potential it holds for transforming rockfall detection practices.


## Overall Implementation and Design
Describe how the hardware was implemented/created, with relevant details of the architecture and design, including general materials (Note: specific details on materials can be addressed in later section “Availability of materials and methods”). The use of diagrams and pictures of the assembled hardware is appropriate. Please also describe any variants and associated implementation differences. 

Note: This is not meant to be an assembly instruction. Assembly instructions, detailed material lists, and construction files must be deposited in an appropriate repository (see Repositories document) and referenced in the section “Build Details”. 

# 2. Quality Control
## Safety
Describe all relevant safety issues or references to a risk assessment if included in the hardware documentation (For example high voltage, chemical safety etc.). If appropriate, discuss the wider context of the use of the hardware and safety issues or risks that may arise in the use environment. 

## Calibration
If the hardware is used for measurements, please detail here how the reliability of measurements, or other hardware properties that are relevant for measurements, has been quantified and explain the results. Be clear about the processes or procedures used to compare the hardware to a standard, as well as the description of the standard calibrated against. 

Detail the general procedures in place for users to calibrate their hardware before or during use. What methods can be used to relate user-generated data to data from other sources?  

Note: Detailed instructions belong in documentation; here, provide insight into how and why the calibration is valid. 

## General Testing
In this section, details can be provided on the testing of hardware functionalities, that are not directly essential for the precision operation of the hardware in the given context (which are in turn, where applicable, handled under Calibration), such as automated movements to position the hardware, repeatability of tool exchanges, recyclability, water-tightness, weight or other possibly relevant characteristics. We encourage the authors to characterise all appropriate functionalities of the hardware, if not already described elsewhere (add reference instead). The testing should define the safe/reliable limits in which the components can be operated (e.g. step size and repeatability of linear motion, force ranges, ratio of devices with leaks when built in a workshop, etc). This will enhance the usability of the hardware or method in other contexts. 

Again: Detailed instructions belong in documentation; here, provide a summary  instead. 

# 3. Application
## Use Cases
Describe at least one example of an application of your hardware. This should include some evidence of output, e.g. data produced by the use of the device or a picture of other types of results. Outline how the quality control in the previous section enables the use of the hardware in this context. We encourage the inclusion of experiment results or the reference to a publication (published or to be published) where these results are detailed. We also encourage pointers to ongoing work. 

Note: In the spirit of openness, we require authors to provide (or link to) datasets along with the submitted graphic representations. We do not impose arbitrary limits on the inclusion of data so please include sufficient empirical detail and results to ensure your data can be easily verified, analysed and clearly interpreted by the wider scientific community. 

# 4. Build Details
## Availability of Materials and Methods
The hardware for this project was constructed using an [Arduino Nano 33 BLE](https://store-usa.arduino.cc/products/arduino-nano-33-ble?srsltid=AfmBOor4lODWf1WTLHpO6Rsf4GWOvRnjMUOSqRXO_J06y5ka-2iJ5dO2) board integrated with the [TinyML Shield](https://store-usa.arduino.cc/products/arduino-tiny-machine-learning-kit?srsltid=AfmBOoojrt-4hQ4G9KjtIXiajwsGtXGNaIXXYTDAT1c_LlG9_NxYmcPi), tailored for embedded machine learning applications. The shield's built-in accelerometer and gyroscope were utilized to capture motion and vibration data, which are essential for detecting rockfall events. A custom enclosure was designed and produced using a [Formlabs 3+](https://formlabs.com/3d-printers/form-3/?srsltid=AfmBOoogctzvkMCPNXJxEQaeboXhmlPcaZkhTJMcOLzRIGzMOPJLnxxH) printer with [Draft V2 photopolymer resin](https://formlabs.com/store/materials/draft-v2-resin/), providing a durable and precise housing for the components. This resin is ideal for high-resolution, rapid prototyping applications, ensuring the enclosure meets the project's requirements for robustness and accuracy.

![Alt Text](images/formlabs_3plus.jpg)
*Figure 1: Formlabs 3+ Printer used for the project.*

The assembly involved securely mounting the [Arduino Nano 33 BLE](https://store-usa.arduino.cc/products/arduino-nano-33-ble?srsltid=AfmBOor4lODWf1WTLHpO6Rsf4GWOvRnjMUOSqRXO_J06y5ka-2iJ5dO2) board and [TinyML Shield](https://store-usa.arduino.cc/products/arduino-tiny-machine-learning-kit?srsltid=AfmBOoojrt-4hQ4G9KjtIXiajwsGtXGNaIXXYTDAT1c_LlG9_NxYmcPi) within the 3D-printed enclosure using standard screws. The electrical connections between components were established through pre-soldered headers, simplifying the process while ensuring a reliable setup. The enclosure was specifically designed using CAD software to ensure a precise fit for the hardware, accommodating the dynamic testing conditions of the project.

While the [Arduino Nano 33 BLE](https://store-usa.arduino.cc/products/arduino-nano-33-ble?srsltid=AfmBOor4lODWf1WTLHpO6Rsf4GWOvRnjMUOSqRXO_J06y5ka-2iJ5dO2) and [TinyML Shield](https://store-usa.arduino.cc/products/arduino-tiny-machine-learning-kit?srsltid=AfmBOoojrt-4hQ4G9KjtIXiajwsGtXGNaIXXYTDAT1c_LlG9_NxYmcPi) are widely available through global distributors, the use of a Formlabs 3+ printer with proprietary  [Draft V2 photopolymer resin](https://formlabs.com/store/materials/draft-v2-resin/) provides a specialized solution for creating high-quality enclosures. These materials and methods are suitable for replicable construction but may require access to advanced 3D printing facilities. The use of only accelerometer and gyroscope data focuses the hardware's functionality on motion-related metrics, aligning with the project’s specific objectives.

## Ease of Build / Design Decision
Have any measures been taken in the design to make the hardware easy to build for other users e.g. reduction of parts, features in the design to make the hardware assembly more reliable? 
What were the decisions made in designing this hardware? Were other designs/options tried? please describe also what did not work. 

## Operating Software and Peripherals
If hardware requires software, details on the operating software and programming language - Please include minimum version compatibility. Additional system requirements, e.g. memory, disk space, processor, input or output devices. 
If the hardware does not require software, detail any required supporting processes or protocols required for use.  

## Dependencies
E.g. other hardware or software projects, modular components, libraries, frameworks, incl. minimum version compatibility. Explicitly state if dependencies are proprietary / closed source. 

## Hardware Documentation / Build Instructions / Files Location
For the assessment of the article, these repositories can be modifiable, for example, on GitHub or GitLab. Once the article has been accepted, these repositories must be moved in a preservation and immutable repository, for example, Zenodo.  

Name: The name of the archive 
Persistent identifier: e.g. DOI, etc. 
Publisher: Name of the person who deposited the documentation 
Date published: yyyy-mm-dd 

# 5. Discussion
## Conclusions
Conclusions, learned lessons from design iterations, learned lessons from use cases, a summary of results. 

## Future Work
Further work pursued by the authors or collaborators; known issues; suggestions for others to improve on the hardware design or testing,, given what you have learned from your design iterations. 

## Author Contributions
Task (e.g. design, assembly, use cases contribution, documentation, paper writing), contribution, author name. 

## Acknowledgments
Please add any relevant acknowledgments to anyone else who supported the project in which the hardware was created, but did not work directly on the hardware itself. 

Please list anyone who helped to create the hardware and software (who may also not be an author of this paper), including their roles and affiliations. 

## References
Please enter references in the Vancouver style and include a DOI where available, citing them in the text with a number in square brackets, e.g. 

[1] Piwowar, H A 2011 Who Shares? Who Doesn't? Factors Associated with Openly Archiving Raw Research Data. PLoS ONE 6(7): e18657. DOI: http://dx.doi.org/10.1371/journal.pone.0018657. 

