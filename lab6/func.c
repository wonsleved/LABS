#include "./cmake-build-debug/header.h"

pMatrix ScanMatrix() {
    pMatrix myMatrix = (pMatrix) malloc(sizeof(Matrix));
    printf("Введите количество строк: ");
    scanf("%d", &myMatrix->row);
    if (myMatrix->row > MAX_ROW) {
        printf("Количество строк должно быть меньше %d. Изменено автоматически на максимальное.\n", MAX_ROW);
        myMatrix->row = MAX_ROW;
    }
    printf("Введите количество столбцов: ");
    scanf("%d", &myMatrix->coll);
    if (myMatrix->coll > MAX_COLL) {
        printf("Количество столбцов должно быть меньше %d. Изменено автоматически на максимальное.\n", MAX_COLL);
        myMatrix->coll = MAX_COLL;
    }
    myMatrix->matrix = (int32_t**) malloc(sizeof(int32_t*) * myMatrix->row);
    for (int32_t i = 0; i < myMatrix->row; i++) {
        myMatrix->matrix[i] = (int32_t*) malloc(sizeof(int32_t) * myMatrix->coll); // Выделение памяти
        printf("Введите %d строку матрицы. %d числа через пробел\n", i + 1, myMatrix->coll);
        scanf("%d", &myMatrix->matrix[i][0]);
        for (int32_t j = 1; j < myMatrix->coll; j++) {
            scanf(" %d", &myMatrix->matrix[i][j]);
        }
    }
    getchar();
    return myMatrix;
}

void PrintMatrix(pMatrix myMatrix) {
    printf("Матрица %d x %d:\n", myMatrix->row, myMatrix->coll);
    for (int32_t i = 0; i < myMatrix->row; i++) {
        for (int32_t j = 0; j < myMatrix->coll; j++) {
            printf("%d ", myMatrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void DelMatrix(pMatrix myMatrix) {
    for (int32_t i = 0; i < myMatrix->row; i++) {
        free(myMatrix->matrix[i]);
    }
    free(myMatrix->matrix);
    myMatrix->matrix = NULL;
}

void TransMatrix(pMatrix myMatrix) {
    pMatrix Trans = (pMatrix) malloc(sizeof(Matrix));
    Trans->row = myMatrix->coll;
    Trans->coll = myMatrix->row;
    Trans->matrix = (int32_t**) malloc(sizeof(int32_t*) * Trans->row);
    for (int32_t i = 0; i < Trans->row; i++) {
        Trans->matrix[i] = (int32_t*) malloc(sizeof(int32_t) * Trans->coll);
        for (int32_t j = 0; j < Trans->coll; j++) {
            Trans->matrix[i][j] = myMatrix->matrix[j][i];
        }
    }
    DelMatrix(myMatrix);
    myMatrix->row = Trans->row;
    myMatrix->coll = Trans->coll;
    myMatrix->matrix = Trans->matrix;
    free(Trans);
}

void PrintMatrixToFile(pMatrix myMatrix) {
    printf("Если хотите записать матрицу в файл, напишите 'y'\n");
    if((char)getchar() != 'y') {
        getchar();
        return;
    }
    FILE *fp = NULL;
    char FileName[100];
    printf("Введите имя файла для записи в него матрицы: ");
    scanf("%s", FileName);
    getchar();
    if ( (fp = fopen(FileName, "wb")) == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }
    fwrite(&myMatrix->row, sizeof(int32_t), 1, fp); // Записать количества строк
    fwrite(&myMatrix->coll, sizeof(int32_t), 1, fp); // Записать количества строк
    for (int32_t i = 0; i < myMatrix->row; i++) {
            fwrite(myMatrix->matrix[i], sizeof(int32_t), myMatrix->coll, fp);
    }
    printf("Матрица записана.\n");
    fclose(fp);
}

pMatrix ScanMatrixFromFile() {
    FILE *fp = NULL;
    char FileName[100];
    printf("Введите имя файла для чтения матрицы: ");
    scanf("%s", FileName);
    getchar();
    if ( (fp = fopen(FileName, "rb")) == NULL) {
        printf("Не удалось открыть файл.\n");
        return NULL;
    }
    pMatrix myMatrix = (pMatrix) malloc(sizeof(Matrix));
    fread(&myMatrix->row, sizeof(int32_t), 1, fp);
    fread(&myMatrix->coll, sizeof(int32_t), 1, fp);

    if ( (myMatrix->row > MAX_ROW) || (myMatrix->coll > MAX_COLL)) {
        printf("Данная матрица имеет больший размер, чем возможно. Выберите другую матрицу");
        fclose(fp);
        return NULL;
    }

    myMatrix->matrix = (int32_t**) malloc(sizeof(int32_t*) * myMatrix->row);
    for (int32_t i = 0; i < myMatrix->row; i++) {
        myMatrix->matrix[i] = (int32_t*) malloc(sizeof(int32_t) * myMatrix->coll);
        fread(myMatrix->matrix[i], sizeof(int32_t), myMatrix->coll, fp);
    }
    fclose(fp);
    printf("Матрица отксканирована.\n");
    return myMatrix;
}

pMatrix GenerateRandomMatrix() {
    srand(time(NULL));
    pMatrix myMatrix = (pMatrix) malloc(sizeof(Matrix));
    myMatrix->row = GetRandom(1, MAX_ROW);
    myMatrix->coll = GetRandom(1, MAX_COLL);
    myMatrix->matrix = (int32_t**) malloc(sizeof(int32_t*) * myMatrix->row);
    for (int32_t i = 0; i < myMatrix->row; i++) {
        myMatrix->matrix[i] = (int32_t*) malloc(sizeof(int32_t) * myMatrix->coll); // Выделение памяти
        for (int32_t j = 0; j < myMatrix->coll; j++) {
            myMatrix->matrix[i][j] = GetRandom(MIN_RAND, MAX_RAND);
        }
    }
    return myMatrix;
}

int32_t GetRandom(const int32_t min, const int32_t max) {
    return rand() % (max - min + 1) + min;
}

int32_t FList() {
    char func_number[5] = {0};
    printf("Выберетие номер функции: ");
    scanf("%4s", func_number);
    scanf("%*c");
    if (!strcmp(func_number, "help")) {
        printf(FUNCTION_LIST);
        return FList();
    }
        // С клавиатуры
    else if (!strcmp(func_number, "1")) {
        printf("Чтение данных из входного потока (с клавиатуры)\n");
        return 1;
    }
        // Из файла
    else if (!strcmp(func_number, "2")) {
        printf("Чтение данных из текстового файла:\n" );
        return 2;
    }
        // Рандом
    else if (!strcmp(func_number, "3")) {
        printf("Случайная генерация данных\n");
        return 3;
    }
        // Выход
    else if (!strcmp(func_number, "4") || !func_number[0]) {
        printf("\nВыход\n");
        return 4;
    }
    else {
        fprintf(stderr, "Нет функции '%s'. Введите help для справочной информации.\n", func_number);
        return FList();
    }
}
