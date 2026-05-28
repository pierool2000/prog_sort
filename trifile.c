#include "include/include.h"

void createfilelist(FILE *f, file_stock_t **head) {
    char word[256];

    while (fscanf(f, "%255s", word) == 1)
        addend(head, word);
    fclose(f);
    return;
}

int main(int argc, char **argv) {
    file_stock_t *head = NULL;
    FILE *f = fopen(argv[1], "r+");

    if (argc != 3) {
        printf("Erreur : argument not valid\n");
        return 84;
    } else if (f == NULL) {
        printf("Erreur : file not valid\n");
        return 84;
    }

    return 0;
}