// Code adapted from https://github.com/hollance/TinyML-HelloWorld-ArduinoUno/blob/master/SineExample/model.cpp
#include <math.h>
#include "model.h"
#include "model_data.h"

inline float relu(float x) {
    return fmaxf(0.0f, x); 
}

inline float sigmoid(float x) {
    return 1.0f / (1.0f + expf(-x));
}

// Now takes two input features
float predict(float x1, float x2) {
    float h1[DENSE1_SIZE];

    // First dense layer: now performs a 2-input dot product for each neuron
    for (int i = 0; i < DENSE1_SIZE; ++i) {
        float z = 0.0f;
        z += x1 * W1(i, 0);
        z += x2 * W1(i, 1);
        z += b1(i);
        h1[i] = relu(z);
    }

    // Second dense layer.
    float y = 0.0f;
    for (int i = 0; i < DENSE2_SIZE; ++i) {
        float h2 = 0.0f;
        for (int j = 0; j < DENSE1_SIZE; ++j) {
            h2 += h1[j] * W2(i, j);
        }
        h2 = relu(h2 + b2(i));

        // Accumulate into final layer
        y += h2 * W3(i);
    }

    // Final bias
    y += b3();

    // Apply sigmoid as requested
    return sigmoid(y);
}
