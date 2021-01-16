# prosthetic_hand_sensors

Under the guidance of our senior Valeska and our mentor Dr Tan, we attempted to create 3D-printed electrodes for use as sensors in a 3D printed prosthetic hand. We then benchmarked the performance of our electrodes against conventional wet electrodes and the Myo Armband to determine the feasibility of our approach.

As project done under the Raffles Science Institute, our project was presented at the Raffles Science Symposium as well as submitted to be judged for the Singapore Science and Engineering Fair. Our team consisted of:

- Lim Caiying
- John-Henry Lim
- Lin Si Qi

Our report has also been added to the repository for convinient reference: [`./report.pdf`](./report.pdf)

## Code

In the esp32_code folder are C sketches used with the ESP32 microcontroller, which was used to obtain readings from the Myo Armband over bluetooth as well as readings from Myoware Sensor Hubs using its ADC pins.

emg_test.ipynb was used to obtain the training data from the ESP32 over USB Serial.

emg_processing.ipynb was used to wrangle the training date and train various classifiers to maximize hand gesture classification accuracy. The code is unfortunately somewhat disorganized due to techniques employed to speed up the training time using multiprocessing.

## Poster

![poster](poster.svg)
