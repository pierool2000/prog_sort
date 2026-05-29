#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct file_stock {
    char word[256];
    struct file_stock *next;
} file_stock_t;

typedef struct pfunc {
    char *name;
    int (*func)(file_stock_t**);
} pfunc_t;

void addend(file_stock_t **head, char *str);

void deleteall(file_stock_t *chain);

void printlist(file_stock_t *head);

int bubblesort(file_stock_t **head);
