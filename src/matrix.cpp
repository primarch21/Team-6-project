#include "../include/matrix.h"
#include <iostream>
#include <stdexcept>
#include <ctime>

// Создание матрицы заданного размера, а также её заполнение случайными значениями
Matrix create_matrix(int rows, int cols) {
    srand(time(0));
    // Диапазон генерации случайных чисел
    const int start = 0;
    const int end = 255;

    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive");
    }

    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new double*[rows];

    for (int i = 0; i < rows; i++) {
        mat.data[i] = new double[cols]();  // () инициализирует нулями
        for (int j = 0; j < cols; j++){
            mat.data[i][j] = rand() % (end - start + 1) + start;  // заполнение матрицы случайными значениями
        }
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

// Вывод матрицы на экран
void print_matrix(Matrix m) {
    if (m.data == nullptr) {
        std::cout << "[Empty matrix]" << std::endl;
        return;
    }
    std::cout << "Image " << m.rows << "x" << m.cols << ":" << std::endl;
    for (int i = 0; i < m.rows; i++) {
        std::cout << "[ ";
        for (int j = 0; j < m.cols; j++) {
            std::cout << m.data[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

// СОБСТВЕННЫЕ ФУНКЦИИ:
// Инферсия изображния
void invert_image(Matrix* img){
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            img->data[i][j] = 255 - img->data[i][j];
        }
    }
}
// Изменение яркости
 void brighten_image(Matrix* img, int value){
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            if (img->data[i][j] + value > 255){
                img->data[i][j] = 255;
            }else{
                img->data[i][j] += value;
            }
        }
    }
}
// Применение контраста
void apply_contrast(Matrix* img, float factor){
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {

            if (img->data[i][j] * factor > 255){
                img->data[i][j] = 255;
            }else{
                img->data[i][j] *= factor;
            }
        }
    }
}
