#include <stdio.h>
#include "library.h"

int main(int argc, char *argv[]) {
    FILE* in = stdin;
    Lab *labyrinth;
    if (argc > 2)
    {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (argc == 2)
    {
        in = fopen(argv[1], "r");
        if (!in)
        {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    labyrinth = readLabFile(in);
    printLab(labyrinth);

    return 0;
}
