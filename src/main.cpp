#include <iostream>
#include "matrix.h"

int main() {
    try {
        // Создаем тестовые матрицы
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);

        // Заполняем данными
        A.data[0][0] = 1; A.data[0][1] = 2;
        A.data[1][0] = 3; A.data[1][1] = 4;
        B.data[0][0] = 5; B.data[0][1] = 6;
        B.data[1][0] = 7; B.data[1][1] = 8;

        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);

        std::cout << "\nMatrix B:" << std::endl;
        print_matrix(B);


        // Освобождаем память (каждую матрицу только один раз)
        free_matrix(A);
        free_matrix(B);

        std::cout << "\nAll tasks completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
