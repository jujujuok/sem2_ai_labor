#include <stdio.h>
#include "library.h"

int main(int argc, char *argv[]) {
    Lab *labyrinth = malloc(sizeof(Lab));

    if (!checkInput(argc, argv)) { return 0; }

    readFile(argv[1], labyrinth);

    printLab(labyrinth);

    if (findSolution(labyrinth, labyrinth->startx, labyrinth->starty)) {
        printLab(labyrinth);
    } else {
        printf("No path could be found.\n");
    }

    return 0;
}
