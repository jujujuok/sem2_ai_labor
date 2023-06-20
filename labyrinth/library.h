//
// Created by BUERKJU on 14.06.2023.
//

#ifndef LABYRINTH_LIBRARY_H
#define LABYRINTH_LIBRARY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAXCOLS  256
#define MAXROWS  256


/* Data type: Labyrinth - ASCII map, costs, direction */

typedef struct labyrinth
{
    char lab[MAXCOLS+2][MAXROWS];
    long costs[MAXCOLS][MAXROWS];
    int maxrow;
    int startx;
    int starty;
    int treasurex;
    int treasurey;
} Lab;


Lab *readLabFile(FILE *file);

void printLab(Lab *lab);

#endif //LABYRINTH_LIBRARY_H
