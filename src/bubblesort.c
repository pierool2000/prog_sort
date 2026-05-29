#include "../include/include.h"

static file_stock_t *current;
static file_stock_t *prev;
static file_stock_t *next;

// inverse les donné dans la list
static int swap(file_stock_t **head) {
    current->next = next->next;
    next->next = current;
    if(prev == NULL)
        *head = next;
    else 
        prev->next = next;
    prev = next;
    return 1; 
}

// parcour la list et regarde s'il  faut swap
static int sort(file_stock_t **head, int swapped, int (*cmp)(file_stock_t*, file_stock_t*)) {
    current = *head;
    prev = NULL;
    while (current->next != NULL) {
        next = current->next;
        if (cmp(current, next) > 0) {
            swapped = swap(head);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return swapped;
}

// relance le sort t'en que la list n'es pas trié 
int bubblesort(file_stock_t **head, char *mode) {
    int swapped = 1;
    int (*cmp)(file_stock_t*, file_stock_t*);
    
    if (*head == NULL)
        return 0;
    if (mode != NULL && strcmp("alpha", mode) == 0)
        cmp = cmp_alpha;
    else
        cmp = cmp_length;
    while (swapped) {
        swapped = 0;
        swapped = sort(head, swapped, cmp);
    }
    return 0;
}