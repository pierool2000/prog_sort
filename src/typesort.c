#include "../include/include.h"

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