#include "include/include.h"

void createfilelist(FILE *f, file_stock_t **head) {
    char word[256];

    while (fscanf(f, "%255s", word) == 1)
        addend(head, word);
    fclose(f);
}

int main(int argc, char **argv) {
    file_stock_t *head = NULL;
    FILE *f;

    if (argc != 3) {
        printf("Erreur : argument not valid\n");
        return 84;
    }
    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Erreur : file not valid\n");
        return 84;
    }
    createfilelist(f, &head);
    bubblesort(&head);
    printlist(head);
    deleteall(head);
    return 0;
}