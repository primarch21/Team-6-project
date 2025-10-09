#include <iostream>
#include "matrix.h"

int main() {
    try {
        int rows = 0;
        int cols = 0;
        std::cout << "Введите размер вашего изображения: ВЫСОТА(в пикселях) ШИРИНА(в пикселях)\n";
        std::cin >> rows >> cols;

        // Создание и вывод тестовой матрицы
        Matrix A = create_matrix(rows, cols);
        std::cout << "Сгенерированное изображние: \n" << std::endl;
        print_matrix(A);

        int brighten_value = 0;
        float contrast_factor = 0.0;
        int operation = 0;

        std::cout << "Введите значение яркости, a также коэффициент контраста: яркость(цел.) контраст(дроб.)\n";
        std::cin >> brighten_value >> contrast_factor;

        std::cout << "Выберите операцию: \n1-инвертировать изображние, 2-изменить яркость, 3-изменить контраст\n Введите число:";
        std::cin >> operation;

        switch (operation)
        {
        case 1: {invert_image(&A); print_matrix(A);}
            break;
        case 2: {brighten_image(&A, brighten_value); print_matrix(A);}
            break;
        case 3: {apply_contrast(&A, contrast_factor); print_matrix(A);}
            break;

        default: {throw std::invalid_argument("Invalid operation");}
            break;
        }

        // Освобождаем память (каждую матрицу только один раз)
        free_matrix(A);

         std::cout << "\nAll tasks completed successfully!" << std::endl;
     } catch (const std::exception& e) {
         std::cerr << "Error: " << e.what() << std::endl;
         return 1;
     }
     return 0;
 }
