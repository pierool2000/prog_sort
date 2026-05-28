#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct file_stock {
    char *word;
    file_stock_t *next;
} file_stock_t;

typedef struct pfunc {
    char *name;
    int (*func)(file_stock_t**);
} pfunc_t;

void addend(file_stock_t **head, char *str);

int delete_all(file_stock_t *chain);