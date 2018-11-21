#pragma once

int getArraySize(); // получение размера массива

void inArray(int* a, int n, std::istream& streamIn); // ввод одномерного массива

void outArray(int* a, int n, std::ostream& streamOut); // вывод одномерного массива

void nullArray(int *a, int n); // обнуление массива

int** createTwoDimensionalArray(int n, int m); // создание двумерного массива

void inTwoDimensionalArray(int** a, int n, int m, std::istream& streamIn); // ввод двумерного массива

void outTwoDimensionalArray(int** a, int n, int m, std::ostream& streamOut); // вывод двумерного массива

void nullTwoDimensionalArray(int** a, int n, int m); // обнуление двумерного массива

void deleteTwoDimensionalArray(int** a, int n); // удаление двумерного массива