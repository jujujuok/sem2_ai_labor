#include <stdio.h>
#include "library.h"
#include "bestPath.h"
#include "terrain_maze.h"

int main(int argc, char *argv[]) {
    Lab *labyrinth = malloc(sizeof(Lab));

    readFile(argv[1], labyrinth);

    printLab(labyrinth);

    if (findSolution(labyrinth, labyrinth->startx, labyrinth->starty)) {
        printf("%s", "A path has been found.");
        printLab(labyrinth);
    }
    else{
        printf("No path could be found.\n");
    }

    // find_terrain_path(labyrinth);
    // printLab(labyrinth);

    free(labyrinth);

    return 0;
}
