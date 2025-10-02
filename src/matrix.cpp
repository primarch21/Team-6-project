#include "matrix.h"
#include <iostream>
#include <stdexcept>
// Создание матрицы заданного размера
Matrix create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        mat.data[i] = new double[cols]();  // () инициализирует нулями
    }
    return mat;
}
// Освобождение памяти матрицы
void free_matrix(Matrix m) {
    if (m.data == nullptr) return;
    for (int i = 0; i < m.rows; i++) {
        delete[] m.data[i];
    }
    delete[] m.data;
}
void print_matrix(Matrix m) {
    if (m.data == nullptr) {
        std::cout << "[Empty matrix]" << std::endl;
        return;
    }
    std::cout << "Matrix " << m.rows << "x" << m.cols << ":" << std::endl;
    for (int i = 0; i < m.rows; i++) {
        std::cout << "[ ";
        for (int j = 0; j < m.cols; j++) {
            std::cout << m.data[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}
//Инверсия изображения
void invert_image(Matrix* img){
    for (int i=0; i < img->rows; i++){
        for (int j = 0; i < img->cols; j++){
            img->data[i][j] -= 255;
        }
    }
}
