cmake_minimum_required(VERSION 3.20)
project(Matrix_Fliter VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Основная библиотека
add_library(matrix_lib src/matrix.cpp)
target_include_directories(matrix_lib PUBLIC include)
# Исполняемый файл
add_executable(matrix_filter src/main.cpp)
target_link_libraries(matrix_fliter PRIVATE matrix_lib)
# Тесты
enable_testing()
add_subdirectory(tests)
