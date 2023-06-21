#include <stdio.h>
#include "library.h"

int main(int argc, char *argv[]) {
    Lab *labyrinth = malloc(sizeof(Lab));

    if (!checkInput(argc, argv)) { return 0; }

    readFile(argv[1], labyrinth);

    printLab(labyrinth);

    findSolution(labyrinth, labyrinth->startx, labyrinth->starty);

    return 0;
}
