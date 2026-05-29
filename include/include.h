#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct file_stock {
    char word[256];
    struct file_stock *next;
} file_stock_t;

typedef struct typesort {
    char *name;
    int (*func)(file_stock_t**, char*);
} typesort_t;

// func list
void addend(file_stock_t **head, char *str);

void deleteall(file_stock_t *chain);

void printlist(file_stock_t *head);
//func

//sort
int cmp_alpha(file_stock_t *a, file_stock_t *b);

int cmp_length(file_stock_t *a, file_stock_t *b);

int bubblesort(file_stock_t **head, char *mode);

