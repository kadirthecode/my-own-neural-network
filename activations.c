#include<math.h>
#include<float.h>
#include"activations.h"


Matrix *apply_activation(const Matrix *A, Matrix *result, ActivationType type){
    if(A->row != result->row || A->col != result->col){
        printf("matris boyutları doğru değil");
        return NULL;
    }
    int n = A->row * A->col;
    switch(type) {
        case ACT_RELU:
            for (int i = 0; i < n; i++){
                result->data[i] = A->data[i] > 0 ? A->data[i] : 0.0f;
            }
            break;
        case ACT_TANH:
            for (int i = 0; i < n; i++){
                result->data[i] = tanhf(A->data[i]);
            }
            break;
        case ACT_SIGMOID:
            for (int i = 0; i < n; i++){
                result->data[i] = 1.0f / (1.0f + expf(-A->data[i]));
            }
            break;
        default:
            printf("geçersiz aktivasyon türü\n");
            return NULL;
    }
    return result;
}

Matrix *apply_activation_derivative(const Matrix *output, Matrix *result, ActivationType type){
    if(output->row != result->row || output->col != result->col){
        printf("matris boyutları doğru değil");
        return NULL;
    }
    int n = output->row * output->col;
    switch(type) {
        case ACT_RELU:
            for (int i = 0; i < n; i++){
                result->data[i] = output->data[i] > 0 ? 1.0f : 0.0f;
            }
            break;
        case ACT_TANH:
            for (int i = 0; i < n; i++){
                result->data[i] = 1.0f - output->data[i] * output->data[i];
            }
            break;
        case ACT_SIGMOID:
            for (int i = 0; i < n; i++){
                result->data[i] = output->data[i] * (1.0f - output->data[i]);
            }
            break;
        default:
            printf("geçersiz aktivasyon türü\n");
            return NULL;
    }
    return result;
}