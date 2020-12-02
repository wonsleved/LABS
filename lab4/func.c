#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "./header.h"


char *get_str() {
    char buffer[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buffer);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buffer);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buffer, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
            n = 0;
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

char *ReadFile() {
    FILE *fp = NULL;
    char filename[MAXFILEPATH];
    char *res = NULL;
    int n = 0;

    char buffer[101] = {0};
    unsigned ch_len, len = 0, str_len = 0;

    printf("Введите путь к файлу: ");
    scanf("%s", filename);
    if ( (strlen(filename) != 0) && (fp = fopen(filename, "r")) != NULL) {
        do {
            n = fscanf(fp, "%100[^\n]", buffer);
            if (n < 0) {
                if (!res) {
                    fprintf(stderr, "Файл %s пуст\n", filename);
                    break;
                }
            } else {
                ch_len = strlen(buffer);
                str_len = len + ch_len;
                res = realloc(res, str_len + 1);
                memcpy(res + len, buffer, ch_len);
                len = str_len;
            }
        } while(n > 0);

        if (len > 0) {
            res[len] = '\0';
        } else {
            res = calloc(1, sizeof(char));
        }
    } else {
        fprintf(stderr, "Невозможно открыть файл %s\n", filename);
        return NULL;
    }

    fclose(fp);
    return res;
}

int WriteFile(char *res) {
    FILE *fp = NULL;
    char filename[MAXFILEPATH];

    printf("Введите путь к файлу: ");
    scanf("%s", filename);

    if ( (strlen(filename) != 0) && (fp = fopen(filename, "w")) != NULL) {
        if (fprintf(fp, "%s", res)) {
            fprintf(stdout, "Успешно записано в файл: %s\n", filename);
            fclose(fp);
            return 1;
        }
        fprintf(stderr, "Не удалось записать в файл: %s\n", filename);
        fclose(fp);
        return 0;
    }
    fprintf(stderr, "Невозможно открыть файл %s\n", filename);
    return 1;
}

char *Sort(const char *str) {
    char *res = NULL;
    res = malloc(sizeof(char) * strlen(str));
    memcpy(res, str, strlen(str));
    char newElement;
    int location;
    for (int i = 1; i < strlen(res); i++)
    {
        newElement = res[i];
        location = i - 1;
        while(location >= 0 && (int)res[location] > (int)newElement)
        {
            res[location+1] = res[location];
            location--;
        }
        res[location+1] = newElement;
    }
    return res;
}

char *Random() {
    char *res = NULL;
    char randChar;
    int randNum = 0;
    if ((res = (char *)malloc(sizeof(char) * RANDNUM)) == NULL) {
		fprintf(stderr, "Не удалось выделить память!\n");
		return NULL;
	}

    srand(time(NULL));
    for (int i = 0; i < RANDNUM; i++) {
        randNum = 32 + 95 * (rand() / (RAND_MAX + 1.0));
        randChar = (char) randNum;
        res[i] = randChar;
    }

    return res;
}

void Symb(char *res) {
    char a;
    int counter = 0;
    printf("Введите символ для его подсчёта: ");
    a = getchar();
    for (int i = 0; i < strlen(res); i++) {
        if (res[i] == a) counter++;
    }
    printf("Всего использований: %d\n", counter);
}
