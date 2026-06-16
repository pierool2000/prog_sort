#include "../include/include.h"


// static int sort(int (*cmp)(file_stock_t*, file_stock_t*)) {
//     file_stock_t *t_cur;

//     t_cur = current->prev;
//     while (t_cur->prev != NULL) {
//         printf("\n___\n%s >< %s\n___\n", temp->word, t_cur->word);
//         if (cmp(temp, t_cur) > 0) {
//             next = t_cur->next;
//             temp->next = next;
//             if (next != NULL)
//                 next->prev = temp;
//             t_cur->next = temp;
//             temp->prev = t_cur;
//             return 0;
//         }
//         t_cur = t_cur->prev;
//     }
//     if (t_cur->prev == NULL) {
//         printf("\n\ntcur etait NULL\n\n");
//         t_cur->prev = temp;
//         temp->next = t_cur;
//         temp->prev = NULL;
//     }
//     return 1;
// }

// static int sort(int (*cmp)(file_stock_t*, file_stock_t*)) {
//     tcur = current->prev;
//     printf("\nnumber 1\n%s\n\n", tcur->word);
//     while (tcur->prev != NULL && cmp(tcur, temp) > 0)
//         tcur = tcur->prev;
//     printf("\nnumber 2\n%s\n\n", tcur->word);
//     if (tcur->prev == NULL) {
//         temp->next = tcur;
//         tcur->prev = temp;
//         temp->prev = NULL;
//         return 1;
//     } else if (cmp(tcur, temp) > 0) {
//         prev = tcur->prev;
//         prev->next = temp;
//         temp->prev = prev;
//         tcur->prev = temp;
//         temp->next = tcur;
//         return 0;
//     } else if (cmp(temp, tcur) > 0) {
//         next = tcur->next;
//         next->prev = temp;
//         temp->next = next;
//         tcur->next = temp;
//         temp->prev = tcur;
//         return 0;
//     }
//     return 0;
// }

static file_stock_t *current;
static file_stock_t *temp;
static file_stock_t *next;
static file_stock_t *tcur;
static file_stock_t *prev;


static int sort(int (*cmp)(file_stock_t*, file_stock_t*))
{
    tcur = current->prev;

    // On recule tant que tcur doit venir APRÈS temp
    while (tcur->prev != NULL && cmp(tcur, temp) > 0)
        tcur = tcur->prev;

    if (cmp(tcur, temp) > 0) {
        // temp se place AVANT tcur (tcur devient la nouvelle tête)
        temp->next = tcur;
        temp->prev = NULL;
        tcur->prev = temp;
        return 1; // nouvelle tête
    } else {
        // temp se place APRÈS tcur
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
        } else
            current = current->next;
        printf("\t%s\n", current->word);
        printlist(*head);
        printf("---\n");
    }
    return 0;
}