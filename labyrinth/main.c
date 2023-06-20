#include <stdio.h>
#include "library.h"

int main(int argc, char *argv[]) {
    FILE* in = stdin;
    Lab *labyrinth;

    checkInput(in, argc, argv);

    char *file_content;
    file_content = readFile(in);
    fileToLab(file_content, &labyrinth);
    free(file_content);

    printLab(labyrinth);

    return 0;
}
