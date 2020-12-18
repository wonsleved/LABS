#ifndef MATRIX_HEADER_H
#define MATRIX_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FUNCTION_LIST   "\n\n" \
                        "1. Чтение данных из входного потока (с клавиатуры)\n" \
                        "2. Чтение данных из бинарного файла\n" \
                        "3. Случайная генерация данных\n" \
                        "4. Выйти из программы\n"

#define MAX_ROW 10
#define MAX_COLL 10

#define MAX_RAND 9
#define MIN_RAND 0

typedef struct Matrix {
    int32_t row;
    int32_t coll;
    int32_t **matrix;
} Matrix, *pMatrix;

int32_t FList();
int32_t GetRandom(int32_t min, int32_t max);

void PrintMatrix(pMatrix myMatrix);
void DelMatrix(pMatrix myMatrix);
void PrintMatrixToFile(pMatrix myMatrix);
void TransMatrix(pMatrix First);

pMatrix ScanMatrix();
pMatrix ScanMatrixFromFile();
pMatrix GenerateRandomMatrix();

#endif //MATRIX_HEADER_H
