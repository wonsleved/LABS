#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./header.h"



void main() {
    printf("\n---   Сортировка вставками   ---\n");
    char *str = NULL;
    char *out = NULL;
    char func_number[5] = {'\0'};
    char yes;

    printf(FUNCTION_LIST);
    while (TRUE) {
        memset(func_number, 0, sizeof(func_number));
        printf("Выберетие номер функции: ");
        scanf("%s", func_number);
        scanf("%*c");

        if (!strlen(func_number) || !strcmp(func_number, "4")) {
            printf("\nВыход\n");
            break;
        }
        else if (!strcmp(func_number, "help")) {
            printf(FUNCTION_LIST);
        }
        // С клавиатуры
        else if (!strcmp(func_number, "1")) {
            printf("Чтение данных из входного потока (с клавиатуры)\n");
            str = get_str();
        }
        // Из файла
        else if (!strcmp(func_number, "2")) {
            printf("Чтение данных из текстового файла:\n" );
            str = ReadFile();
			scanf("%*c");
        }
        // Рандом
        else if (!strcmp(func_number, "3")) {
            printf("Случайная генерация данных\n");
            str = Random();
        }
        else {
            fprintf(stderr, "Нет функции '%s'. Введите help для справочной информации.\n", func_number);
        }

        if ( str == NULL ) continue;

        printf("TEXT: %s\n", str);
        Symb(str);
        out = Sort(str);
        printf("\nSORTED: %s\n\n", out);

        scanf("%*c");
        printf("Если хотите записать результат в файл, напишите 'y'\n");
        yes = getchar();
        if(yes == 'y') WriteFile(out);
        free(str); free(out); str = NULL;
    }
}
