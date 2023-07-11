//
// Created by BUERKJU on 24.06.2023.
//

#ifndef LABYRINTH_TERRAIN_MAZE_H
#define LABYRINTH_TERRAIN_MAZE_H

#include "library.h"


void find_terrain_path(Lab *labyrinth);
int calc_cost(Lab *lab, int x, int y, int prev_cost);


#endif //LABYRINTH_TERRAIN_MAZE_H
