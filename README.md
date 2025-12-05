# Arduino-Uno-R3-Rain-prediction
A small NN predicting chance of rain from humidity+temperature(+light) data and displaying the prediction. Works on Arduino UNO R3.

Code (heavily) based on https://github.com/hollance/TinyML-HelloWorld-ArduinoUno/tree/master

Training dataset: Kaggle sujithmandala/simple-rainfall-classification-dataset

Arduino components used:
- phototransitor
- temperature sensor
- humidity sensor (to be added)
- [Optional] LCD display

First train the model by running the `.ipynb` file, then copy-paste the trained weights to `model_data.cpp`.

TODO: adjust the sensor value scaling to match the dataset range.

## Board setup:

**Display**: 

<img width="250" height="300" alt="image" src="https://github.com/user-attachments/assets/84b658ea-9aed-425e-a814-8d9160256f93" />


- the Potentiometer you turn to make the light appear - it seems necessary(?)
- the resitor for 15 is necessary as well

**Phototransitor (measures light):**

one leg to power,

 the other one to A0 + resistor to ground

<img width="220" alt="display" src="https://github.com/user-attachments/assets/56b652ec-05ca-4967-8683-31ea9a95f0e6" />

**Temperature sensor:**

let the flat part face you: for the three legs to power, A1, ground respectively.

<img width="220" alt="display" src="https://github.com/user-attachments/assets/497ad963-5111-47f6-aebf-68d15777e1a1" />

**Working display:**

<img width="500" alt="display" src="https://github.com/user-attachments/assets/723f9153-b60d-4455-95fa-23f3c4bfa6d4" />


