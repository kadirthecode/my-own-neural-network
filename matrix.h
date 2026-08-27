#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix {
    int row;
    int col;
    float *data;
} Matrix;

Matrix *initmatrix(int row, int col);
void delmat(Matrix **A);

void matmul(const Matrix *A, const Matrix *B, Matrix *result);
void matadd(const Matrix *A, const Matrix *B, Matrix *result);
void matsub(const Matrix *A, const Matrix *B, Matrix *result);
void hadamard(const Matrix *A, const Matrix *B, Matrix *result);
void transpoze(const Matrix *A, Matrix *result);
void matadds(const Matrix *A, float k, Matrix *result);
void matmuls(const Matrix *A, float k, Matrix *result);

void printmat(const Matrix *A);

#endif