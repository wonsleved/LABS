#ifndef LIST_HEADER_H
#define LIST_HEADER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Item {
    char data;
    struct Item *next;
} Item;

typedef struct List {
    Item *head;
    Item *tail;
} List;

List *list_new();
void list_delete(List **list);
void list_print(const List *list);
int list_push_back(List *list, char data);
void MySort(List *list);
void ScanToList(List *list);
char DelNext(List *list, Item *item);
int DelHead(List *list);

#endif //LIST_HEADER_H
