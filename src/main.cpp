#include <iostream>
#include "matrix.h"

int main() {
    try {
        // Создаем тестовые матрицы
        Matrix A = create_matrix(3, 3);
        float factor = 4.0;


        // Заполняем данными
        A.data[0][0] = 42; A.data[0][1] = 223; A.data[0][2] = 25;
        A.data[1][0] = 12; A.data[1][1] = 2; A.data[1][2] = 87;
        A.data[2][0] = 1; A.data[2][1] = 255; A.data[2][2] = 0;

        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);

        apply_contrast(&A, factor);
        print_matrix(A);

        // Освобождаем память (каждую матрицу только один раз)
        free_matrix(A);
        std::cout << "\nAll tasks completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
