#include "../include/include.h"

static file_stock_t *current;
static file_stock_t *temp;
static file_stock_t *next;
static file_stock_t *tcur;


static int sort(int (*cmp)(file_stock_t*, file_stock_t*)) {
    tcur = current;
    while (tcur->prev != NULL && cmp(tcur, temp) > 0)
        tcur = tcur->prev;
    if (cmp(tcur, temp) > 0) {
        temp->next = tcur;
        temp->prev = NULL;
        tcur->prev = temp;
        return 1;
    } else {
        next = tcur->next;
        tcur->next = temp;
        temp->prev = tcur;
        temp->next = next;
        if (next != NULL)
            next->prev = temp;
        return 0;
    }
}

int insertionsort(file_stock_t **head, char *mode) {
    int (*cmp)(file_stock_t*, file_stock_t*);
    
    if (*head == NULL)
        return 0;
    cmp = get_cmp(mode);
    if (cmp == NULL)
        return 0;
    current = *head;
    while (current->next != NULL) {
        next = current->next;
        if (cmp(current, next) > 0) {
            temp = next;
            next = temp->next;
            current->next = next;
            if (next != NULL)
                next->prev = current;
            if (sort(cmp) == 1)
                *head = temp;
        } else
            current = current->next;
    }
    return 0;
}