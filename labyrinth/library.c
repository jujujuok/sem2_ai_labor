//
// Created by BUERKJU on 14.06.2023.
//

#include <ctype.h>
#include "library.h"

void readFile(char *filename, Lab *labyrinth) {
    FILE *fptr;
    fptr = fopen(filename, "r");

    char line[MAXROWS];
    int row = 0;
    while (fgets(line, MAXROWS, fptr)) {
        // check if labyrinth is valid
        for (int i = 0; i < strlen(line); ++i) {
            labyrinth->lab[row][i] = line[i];
            labyrinth->costs[row][i] = 0;
            // Alternative: memcpy

            if (toupper(labyrinth->lab[row][i]) == 'S') {
                labyrinth->startx = row;
                labyrinth->starty = i;
            } else if (toupper(labyrinth->lab[row][i]) == 'X') {
                labyrinth->treasurex = row;
                labyrinth->treasurey = i;
            }
        }
        row += 1;
    }

    labyrinth->maxrow = row;
}

void printLab(Lab *labyrinth) {
    for (int i = 0; i < labyrinth->maxrow; i++) {
        for (int j = 0; j < strlen(labyrinth->lab[i]); j++) {
            printf("%c", labyrinth->lab[i][j]);
            // Alternative: printf "%s"
        }
    }
}

bool checkInput(int length_params, char *params[]) {
    return length_params > 1;
}

bool findSolution(Lab *labyrinth, int x, int y) {
    if (x == labyrinth->treasurex && y == labyrinth->treasurey) return 1;

    if (labyrinth->lab[x][y] == '#' || labyrinth->costs[x][y]) //costs ==labyrinth->lab[x][y] == '.')
    { return 0; }

    labyrinth->costs[x][y] = 1;
    if (labyrinth->lab[x][y] == ' ') labyrinth->lab[x][y] = '.';

    if (findSolution(labyrinth, x, y + 1 )||
        findSolution(labyrinth, x + 1, y) ||
        findSolution(labyrinth, x - 1, y) ||
        findSolution(labyrinth, x, y - 1)) { return 1; }
    else { labyrinth->lab[x][y] = ' '; }
    return 0;
    //überprüfen ob man schon mal da war
}