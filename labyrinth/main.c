#include <stdio.h>
#include "library.h"
#include "terrain_maze.h"

int main(int argc, char *argv[]) {
    Lab *labyrinth = malloc(sizeof(Lab));

    if (!checkInput(argc, argv)) { return 0; }

    readFile(argv[1], labyrinth);

    printLab(labyrinth);

    if (findSolution(labyrinth, labyrinth->startx, labyrinth->starty)) {
        printf("%s", "A path has been found.");
        printLab(labyrinth);
    }
    else{
        printf("No path could be found.\n");
    }

    int bestPath = findBestPath(labyrinth);
    if (bestPath != -1) {
        printf("The best path has been found with a length of %d.\n", bestPath);
    }
    else {
        printf("No path could be found.\n");
    }

    free(labyrinth);

    return 0;
}
