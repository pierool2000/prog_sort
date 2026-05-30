#include "include/include.h"

typesort_t commads[] = {
    {"bubble", bubblesort},
    {NULL,      NULL}
};

// récupére le mots dans le fichier et les même dans un list
static void createfilelist(FILE *f, file_stock_t **head) {
    char word[256];

    while (fscanf(f, "%255s", word) == 1)
        addend(head, word);
    fclose(f);
}

static void createnewfile(file_stock_t *head, char **argv) {
    FILE *out = fopen(argv[2], "w");
    file_stock_t *current = NULL;

    if (out == NULL) {
        printf("Erreur : file not valid\n");
        exit(84);
    }
    current = head;
    while (current != NULL) {
        fprintf(out, "%s\n", current->word);
        current = current->next;
    }
    fclose(out);
}

// selection du type de sort en du mode sort
int tryinpout(file_stock_t **head, char **argv) {
    char *mode = NULL;

    if (argv[4] != NULL)
        mode = argv[4];
    for (int i = 0; commads[i].name != NULL; i++) {
        if (strcmp(commads[i].name, argv[3]) == 0) {
            commads[i].func(head, mode);
        }
    }   
    return 0;
}

int main(int argc, char **argv) {
    file_stock_t *head = NULL;
    FILE *f;

    if (argc < 4) {
        printf("Erreur : argument not valid\n");
        return 84;
    }
    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Erreur : file not valid\n");
        return 84;
    }
    createfilelist(f, &head);
    tryinpout(&head, argv);
    createnewfile(head, argv);
    deleteall(head);
    return 0;
}