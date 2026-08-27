#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix *initmatrix(int row, int col) {
    if (row <= 0 || col <= 0) {
        printf("Gecersiz matris boyutu: (%d, %d)\n", row, col);
        return NULL;
    }
    Matrix *newMatrix = (Matrix *)malloc(sizeof(Matrix));
    if (newMatrix == NULL) {
        printf("Matris struct olusturmada bellek hatasi\n");
        return NULL;
    }
    newMatrix->row = row;
    newMatrix->col = col;
    newMatrix->data = (float *)calloc((size_t)row * col, sizeof(float));
    if (newMatrix->data == NULL) {
        free(newMatrix);
        printf("Matris data olusturmada bellek hatasi\n");
        return NULL;
    }
    return newMatrix;
}

void delmat(Matrix **A) {
    if (A == NULL || *A == NULL) return;
    if ((*A)->data != NULL) {
        free((*A)->data);
        (*A)->data = NULL;
    }
    free(*A);
    *A = NULL;
}

void matmul(const Matrix *A, const Matrix *B, Matrix *result) {
    if (A == NULL || B == NULL || result == NULL) return;
    if (A->col != B->row || A->row != result->row || B->col != result->col) {
        printf("Matris boyutlari carpima uygun degil\n");
        return;
    }
    memset(result->data, 0, (size_t)result->row * result->col * sizeof(float));
    for (int i = 0; i < A->row; i++) {
        for (int k = 0; k < A->col; k++) {
            float a = A->data[i * A->col + k];
            for (int j = 0; j < B->col; j++) {
                result->data[i * result->col + j] += a * B->data[k * B->col + j];
            }
        }
    }
}

void matadd(const Matrix *A, const Matrix *B, Matrix *result) {
    if (A == NULL || B == NULL || result == NULL) return;
    if (A->row != B->row || A->col != B->col || 
        A->row != result->row || A->col != result->col) {
        printf("Matris boyutlari esit degil\n");
        return;
    }
    int total = A->row * A->col;
    for (int i = 0; i < total; i++) {
        result->data[i] = A->data[i] + B->data[i];
    }
}

void matsub(const Matrix *A, const Matrix *B, Matrix *result) {
    if (A == NULL || B == NULL || result == NULL) return;
    if (A->row != B->row || A->col != B->col || 
        A->row != result->row || A->col != result->col) {
        printf("Matris boyutlari esit degil\n");
        return;
    }
    int total = A->row * A->col;
    for (int i = 0; i < total; i++) {
        result->data[i] = A->data[i] - B->data[i];
    }
}

void hadamard(const Matrix *A, const Matrix *B, Matrix *result) {
    if (A == NULL || B == NULL || result == NULL) return;
    if (A->row != B->row || A->col != B->col || 
        A->row != result->row || A->col != result->col) {
        printf("Matris boyutlari esit degil\n");
        return;
    }
    int total = A->row * A->col;
    for (int i = 0; i < total; i++) {
        result->data[i] = A->data[i] * B->data[i];
    }
}

void transpoze(const Matrix *A, Matrix *result) {
    if (A == NULL || result == NULL) return;
    if (A->row != result->col || A->col != result->row) {
        printf("Transpoz icin hedef matris boyutu uyusmuyor\n");
        return;
    }
    if (A == result) {
        float *temp = (float *)malloc((size_t)A->row * A->col * sizeof(float));
        if (temp == NULL) return;
        for (int i = 0; i < A->row; i++) {
            for (int j = 0; j < A->col; j++) {
                temp[j * A->row + i] = A->data[i * A->col + j];
            }
        }
        memcpy(result->data, temp, (size_t)A->row * A->col * sizeof(float));
        int t = result->row;
        result->row = result->col;
        result->col = t;
        free(temp);
        return;
    }
    for (int i = 0; i < A->row; i++) {
        for (int j = 0; j < A->col; j++) {
            result->data[j * result->col + i] = A->data[i * A->col + j];
        }
    }
}

void matadds(const Matrix *A, float k, Matrix *result) {
    if (A == NULL || result == NULL) return;
    if (A->row != result->row || A->col != result->col) {
        printf("Boyut uyusmazligi\n");
        return;
    }
    int total = A->row * A->col;
    for (int i = 0; i < total; i++) {
        result->data[i] = A->data[i] + k;
    }
}

void matmuls(const Matrix *A, float k, Matrix *result) {
    if (A == NULL || result == NULL) return;
    if (A->row != result->row || A->col != result->col) {
        printf("Boyut uyusmazligi\n");
        return;
    }
    int total = A->row * A->col;
    for (int i = 0; i < total; i++) {
        result->data[i] = A->data[i] * k;
    }
}

void printmat(const Matrix *A) {
    if (A == NULL || A->data == NULL) return;
    for (int i = 0; i < A->row; i++) {
        for (int j = 0; j < A->col; j++) {
            printf("%f ", A->data[i * A->col + j]);
        }
        printf("\n");
    }
}