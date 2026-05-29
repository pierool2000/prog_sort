#include "../include/include.h"

// rajoute automatiquement a la fin d'une list
void addend(file_stock_t **head, char *str) {
    file_stock_t *current = NULL;
    file_stock_t *new = malloc(sizeof(file_stock_t));

    if (new->word == NULL) {
        free(new);
        return;
    }
    new->next = NULL;
    strcpy(new->word, str);
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

// supprime entiérement un list
void deleteall(file_stock_t *chain) {
    file_stock_t *current = chain;
    file_stock_t *del = NULL;

    while (current != NULL) {
        del = current;
        current = current->next;
        free(del);
    }
    return;
}

// affiche list
void printlist(file_stock_t *head) {
    file_stock_t *current = head;

    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
    return;
}
