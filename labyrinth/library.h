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

typedef struct labyrinth {
    char lab[MAXCOLS + 2][MAXROWS];
    long costs[MAXCOLS][MAXROWS];
    int maxrow;
    int startx;
    int starty;
    int treasurex;
    int treasurey;
} Lab;

bool checkInput(int length_params, char *params[]);

void readFile(char *filename, Lab *lab);

void printLab(Lab *labyrinth);

bool findSolution(Lab *labyrinth, int x, int y);

#endif //LABYRINTH_LIBRARY_H
