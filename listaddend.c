#include "include/include.h"

void addend(file_stock_t **head, char *str) {
    file_stock_t *current = NULL;
    file_stock_t *new = malloc(sizeof(file_stock_t));

    if (new == NULL)
        return;
    new->next = NULL;
    new->word = str;
    if (*head == NULL) {
        *head = new;
        return;
    }
    current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new;
    return;
}

void delete_all(file_stock_t *chain) {
    file_stock_t *current = chain;
    file_stock_t *del = NULL;

    while (current != NULL) {
        del = current;
        current = current->next;
        free(del->word);
        free(del);
    }
    return;
}