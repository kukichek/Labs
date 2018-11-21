#pragma once

int getArraySize(); // ��������� ������� �������

void inArray(int* a, int n, std::istream& streamIn); // ���� ����������� �������

void outArray(int* a, int n, std::ostream& streamOut); // ����� ����������� �������

void nullArray(int *a, int n); // ��������� �������

int** createTwoDimensionalArray(int n, int m); // �������� ���������� �������

void inTwoDimensionalArray(int** a, int n, int m, std::istream& streamIn); // ���� ���������� �������

void outTwoDimensionalArray(int** a, int n, int m, std::ostream& streamOut); // ����� ���������� �������

void nullTwoDimensionalArray(int** a, int n, int m); // ��������� ���������� �������

void deleteTwoDimensionalArray(int** a, int n); // �������� ���������� �������