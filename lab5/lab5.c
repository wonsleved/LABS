#include "./header.h"

void main() {
        char c;
        while(1) {
        List *l = list_new(); // Создать лист
        ScanToList(l); // Ввод строки
        list_print(l); // Вывести строку
        MySort(l); // Первая буква строки фиксируется, слова не начинающиеся на эту букву удаляются
        list_print(l); // Вывести кнечное значение строки
        list_delete(&l); // Удлить всю строку и лист
                printf("Хотите продолижть - введите 'y'\n");
                c = getchar();
                if (c == 'y') {
                        getchar();
                }
                else {
                        break;
                }
        }
        printf("Выход\n");
}
