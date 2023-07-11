//
// Created by BUERKJU on 24.06.2023.
//

#include "terrain_maze.h"


#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

void find_terrain_path(Lab *labyrinth) {
    // cost array 0
    for (int i = 0; i < MAXROWS; ++i) {
        for (int j = 0; j < MAXCOLS; ++j) {
            labyrinth->costs[i][j] = INT_MAX;
        }
    }
    calc_cost(labyrinth, labyrinth->startx, labyrinth->starty, 1);

    //find best path checking from treasure

}


int calc_cost(Lab *lab, int x, int y, int prev_cost) {
    if (lab->lab[x][y] == '#') {
        lab->costs[x][y] = -1;
    } else {

        // TODO

        int cost = isdigit(lab->lab[x][y]) ? lab->lab[x][y] - '0' : 1;
        cost = prev_cost + cost;
        if (lab->costs[x][y] > cost) {
            lab->costs[x][y] = cost;
            return 1;
        } else if (lab->costs[x][y] == cost) {
            return 0;
        } else {
            calc_cost(lab, x, y + 1, cost);
            calc_cost(lab, x, y - 1, cost);
            calc_cost(lab, x + 1, y, cost);
            calc_cost(lab, x - 1, y, cost);
        }
    }
    return 0;
}