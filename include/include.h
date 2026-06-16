#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct file_stock {
    char word[256];
    struct file_stock *next;
    struct file_stock *prev;
} file_stock_t;

typedef struct typesort {
    char *name;
    int (*func)(file_stock_t**, char*);
} typesort_t;

typedef struct typetrie {
    char *name;
    int (*cmp)(file_stock_t*, file_stock_t*);
} typetrie_t;

// func list
void addend(file_stock_t **head, char *str);

void deleteall(file_stock_t *chain);

void printlist(file_stock_t *head);
//func

//sort
int cmp_alpha(file_stock_t *a, file_stock_t *b);

int cmp_length(file_stock_t *a, file_stock_t *b);

int cmp_revalpha(file_stock_t *a, file_stock_t *b);

int cmp_revlength(file_stock_t *a, file_stock_t *b);

int (*get_cmp(char *mode))(file_stock_t*, file_stock_t*);

int bubblesort(file_stock_t **head, char *mode);

int insertionsort(file_stock_t **head, char *mode);

