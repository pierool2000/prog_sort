#include "../include/include.h"

typetrie_t cmp_list[] = {
    {"alpha", cmp_alpha},
    {"len", cmp_length},
    {"revalpha", cmp_revalpha},
    {"revlen", cmp_revlength},
    {NULL,      NULL}
};

int utf8_strlen(const char *str) {
    int len = 0;

    while (*str) {
        if ((*str & 0xC0) != 0x80)
            len++;
        str++;
    }
    return len;
}

// tri alphabéthique 
int cmp_alpha(file_stock_t *a, file_stock_t *b) {
    return strcmp(a->word, b->word);
}

// tri parre la longeur
int cmp_length(file_stock_t *a, file_stock_t *b) {
    return utf8_strlen(a->word) - utf8_strlen(b->word);
}

// tri alphabéthique revers
int cmp_revalpha(file_stock_t *a, file_stock_t *b) {
    return strcmp(a->word, b->word) * -1;
}

// tri parre la longeur revers
int cmp_revlength(file_stock_t *a, file_stock_t *b) {
    return (utf8_strlen(a->word) - utf8_strlen(b->word)) * -1;
}

int (*get_cmp(char *mode))(file_stock_t*, file_stock_t*) {
    int i = 0;

    while (cmp_list[i].name != NULL && strcmp(cmp_list[i].name, mode) != 0)
        i++;
    return cmp_list[i].cmp;
}