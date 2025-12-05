# Arduino-Uno-R3-Rain-prediction
A small NN predicting chance of rain from humidity+temperature(+light) data and displaying the prediction. Works on Arduino UNO R3.

Code (heavily) based on https://github.com/hollance/TinyML-HelloWorld-ArduinoUno/tree/master

Training dataset: Kaggle sujithmandala/simple-rainfall-classification-dataset

Arduino components used:
- phototransitor
- temperature sensor
- humidity sensor (to be added)
- LCD display

First train the model by running the `.ipynb` file, then copy-paste the trained weights to `model_data.cpp`.

TODO: adjust the sensor value scaling to match the dataset range.
