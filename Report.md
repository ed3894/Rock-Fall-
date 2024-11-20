


# Overview

## Title

## Authors
1. Ahmed, Ahmed 
2. Deal, Ethan 
3. Ding, Yidan 

## Abstract

This project explores the development of a lightweight, embedded system for real-time rockfall detection using an Arduino 33 BLE sensor equipped with a TinyML shield. A three-axis accelerometer and gyroscope were utilized to record vibrations caused by rocks rolling down a slope simulated in a soil-filled bin. The experimental setup involved rolling rocks in varying quantities and positions, alongside background noise recordings, resulting in 200 labeled samples of 1.5 seconds at 100 Hz. Data preprocessing was performed using spectral features (FFT) and processed through a neural network in Edge Impulse. The network architecture consisted of a 78-feature input layer, two dense layers (20 and 10 neurons), and a binary output layer to classify rockfall events versus background noise. Initial results demonstrate the system's ability to distinguish rockfall activity under controlled conditions. Future improvements include expanding the dataset with varied terrain and environmental noise, optimizing model parameters, and field validation to enhance real-world applicability.
