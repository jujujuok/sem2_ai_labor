//
// Created by BUERKJU on 14.06.2023.
//

#include "library.h"

char *readFile(FILE *file) {
    while (fgetc(file)) {

    }

    return NULL;
}

void fileToLab(char *file_content, Lab **labyrinth) {

}


void printLab(Lab *lab) {
    for (int i = 0; i < MAXROWS && lab[i][0] != '\0'; i++) {
        for (int j = 0; j < MAXCOLS && lab[i][j] != '\0'; j++) {
            printf("%c", lab[i][j]);
        }
        printf("\n");
    }
}

void checkInput(FILE *in, int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2) {
        in = fopen(argv[1], "r");
        if (!in) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
}