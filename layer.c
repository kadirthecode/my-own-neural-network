#include "layer.h"
#include <stdlib.h>
#include <stdio.h>

Layer *create_base_layer(int input_size, int output_size) {
    if (input_size <= 0 || output_size <= 0) {
        printf("Gecersiz katman boyutlari\n");
        return NULL;
    }
    Layer *layer = malloc(sizeof(Layer));
    if (layer == NULL) {
        printf("Layer struct allocate edilemedi\n");
        return NULL;
    }
    layer->input_size = input_size;
    layer->output_size = output_size;
    layer->output = initmatrix(output_size, 1);
    layer->grad_input = initmatrix(input_size, 1);
    if (layer->output == NULL || layer->grad_input == NULL) {
        printf("Layer temel buffer'lari allocate edilemedi.\n");
        delmat(&layer->output);
        delmat(&layer->grad_input);
        free(layer);
        return NULL;
    }
    layer->params = NULL;
    layer->forward = NULL;
    layer->backward = NULL;
    layer->get_params = NULL;
    layer->free = NULL;
    return layer;
}

void free_base_layer(Layer *layer) {
    if (layer == NULL) return;
    if (layer->output != NULL) {
        delmat(&layer->output);
    }
    if (layer->grad_input != NULL) {
        delmat(&layer->grad_input);
    }
    free(layer);
}