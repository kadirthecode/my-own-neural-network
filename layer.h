#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"

typedef struct Layer Layer;

struct Layer {
    int input_size;
    int output_size;
    Matrix *output;
    Matrix *grad_input;
    void *params;
    void (*forward)(Layer *self, const Matrix *input);
    void (*backward)(Layer *self, const Matrix *grad_output);
    void (*get_params)(Layer *self, Matrix ***params_out, Matrix ***grads_out, int *count);
    void (*free)(Layer *self);
};

Layer *create_base_layer(int input_size, int output_size);
void free_base_layer(Layer *layer);

#endif // LAYER_H