#include "./header.h"

List *list_new() {
    List *ptr = (List *) malloc(sizeof(List));
    ptr->head = ptr->tail = NULL;
    return ptr;
}

void list_delete(List **list) {
    Item *ptr = (*list)->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(*list);
    *list = NULL;
}

void list_print(const List *list) {
    Item *ptr = list->head;
    while (ptr) {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int list_push_back(List *list, char data) {
    if (list == NULL) {
        fprintf(stderr, "List is not initialized!\n");
        return 1;
    }
    Item *ptr = NULL;
    if ( !(ptr = (Item *) malloc(sizeof(Item))) ) {
        return 1;
    }
    ptr->data = data;
    ptr->next = NULL;
    if ( (list->head) == NULL) {
        list->head = ptr;
        list->tail = ptr;
    } else {
        list->tail->next = ptr;
        list->tail = ptr;
    }
    return 0;
}

void MySort(List *list) {
    if (list == NULL || list->head == NULL) {
        fprintf(stderr, "Список пуст\n");
        return;
    }

    char preNext = ' ';
    while (list->head->data == ' ' || list->head->data == '\t') {
        printf("CHAR '%c'\n", list->head->data);
        if (!DelHead(list)) {
            printf("ERR");
            return;
        }
    }
    printf("DBG '%c'\n", list->head->data);
    char c = list->head->data;
    Item *myNext = list->head->next;
    while (myNext->data != ' ') {
        myNext = myNext->next;
        if (myNext == NULL) return;
    }
    while (myNext->next != NULL) {
        if ( (myNext->data == ' ' || myNext->data == '\t') && myNext->next->data == c && (preNext == ' ' || preNext == '\t')) {
            do {
                if (myNext->data == '\t') myNext->data = ' ';
                myNext = myNext->next;
                if (myNext == NULL) return;
            } while ( myNext->data != ' ' && myNext->data != '\t');
        } else {
            preNext = DelNext(list, myNext);
        }
    }
}

void ScanToList(List *list) {
    printf("Введите строку: ");
    int i = 0;
    char a = '\0';
    while (a != '\n') {
        a = (char) getchar();
        if (a != '\n') {
            if (list_push_back(list, a)) {
                fprintf(stderr, "List push back ошибка!");
                return;
            }
            i++;
        }
    }
}

char DelNext(List *list, Item *item) {
    if (item == NULL) {
        fprintf(stderr, "Элемент отсутствует");
        return 0;
    }
    else if ((item)->next == NULL) {
        fprintf(stderr, "Следующий элемет отсутствует");
        return 0;
    }
    Item *tmp = item->next->next; // Указатель на элемент после удаляемого
    char retChar = item->next->data; // Значение следующейго элемента
    free(item->next); // Удаление следующего элемента
    item->next = tmp; // Пробросить указатель через удалённый элемент
    if ( (item->next) == NULL ) { // Конец списка
        list->tail = item;
    }
    return retChar;
}

int DelHead(List *list) {
    if (list->head == NULL || list->head->next == NULL) {
        fprintf(stderr, "Список должен иметь хотябы 1 элемент\n");
        return 0;
    }
    Item *tmp = list->head;
    list->head = list->head->next;
    free(tmp);
    return 1;
}
