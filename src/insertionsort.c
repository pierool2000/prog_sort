#include "../include/include.h"

static file_stock_t *current;
static file_stock_t *temp;
static file_stock_t *next;

static int sort(int (*cmp)(file_stock_t*, file_stock_t*)) {
    file_stock_t *t_cur;

    t_cur = current;
    do {
        if (cmp(temp, t_cur) > 0) {
            next = t_cur->next;
            temp->next = next;
            if (next != NULL)
                next->prev = temp;
            t_cur->next = temp;
            temp->prev = t_cur;
            return 0;
        }
        t_cur = t_cur->prev;
    } while (t_cur->prev != NULL);
    if (t_cur->prev == NULL) {
        t_cur->prev = temp;
        temp->next = t_cur;
        temp->prev = NULL;
    }
    return 1;
}

int insertionsort(file_stock_t **head, char *mode) {
    int (*cmp)(file_stock_t*, file_stock_t*);
    
    if (*head == NULL)
        return 0;
    if (mode != NULL && strcmp("alpha", mode) == 0)
        cmp = cmp_alpha;
    else
        cmp = cmp_length;
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
            current = current->next;
        } else
            current = current->next;
        printlist(*head);
        printf("---\n");
    }
    return 0;
}