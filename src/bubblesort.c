#include "../include/include.h"

static file_stock_t *current;
static file_stock_t *prev;
static file_stock_t *next;

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

static int sort(file_stock_t **head, int swapped) {
    current = *head;
    prev = NULL;
    while (current->next != NULL) {
        next = current->next;
        if (strcmp(current->word, next->word) > 0) {
            swapped = swap(head);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return swapped;
}

int bubblesort(file_stock_t **head) {
    int swapped = 1;

    if (*head == NULL)
        return 0;
    while (swapped) {
        swapped = 0;
        swapped = sort(head, swapped);
    }
    return 0;
}