#pragma once
typedef struct {
double** data;
int rows;
int cols;
} Matrix;

Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix m);

// Вспомогательные функции
void print_matrix(Matrix m);
Matrix matrix_from_array(double* data, int rows, int cols);

// Собственные функции
void apply_contrast(Matrix* img, float factor);
