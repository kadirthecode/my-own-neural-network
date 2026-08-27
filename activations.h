#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include "matrix.h"

enum ActivationType {
    ACT_RELU,
    ACT_TANH,
    ACT_SIGMOID
};

Matrix *apply_activation(const Matrix *A, Matrix *result, ActivationType type);
Matrix *apply_activation_derivative(const Matrix *output, Matrix *result, ActivationType type)

#endif