#include "./cmake-build-debug/header.h"


void main() {
    printf("\n---   Сортировка ASCII вставками   ---\n");
    int n;
    pMatrix myMatrix = NULL;
    printf(FUNCTION_LIST);
    while (TRUE) {
        switch ( n = FList() ) {
            case 1: { // С клавиатуры
                if ((myMatrix = ScanMatrix()) == NULL) continue;
                break;
            }
            case 2: { // Из файла
                if ((myMatrix = ScanMatrixFromFile()) == NULL) continue;
                break;
            }
            case 3: { // Рандом
                if ((myMatrix = GenerateRandomMatrix()) == NULL) continue;
                break;
            }
            default: {
                break;
            }
        }
        if (n == 4) break;
        if (myMatrix == NULL) continue;
        PrintMatrix(myMatrix);
        PrintMatrixToFile(myMatrix);
        TransMatrix(myMatrix);
        printf("Транспонированная матрица:\n");
        PrintMatrix(myMatrix);
        PrintMatrixToFile(myMatrix);
        TransMatrix(myMatrix);
        printf("Дважды транспонированная матрица:\n");
        PrintMatrix(myMatrix);
        PrintMatrixToFile(myMatrix);

        DelMatrix(myMatrix);
        free(myMatrix);
        myMatrix = NULL;
    }
}
