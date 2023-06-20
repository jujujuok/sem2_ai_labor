//
// Created by BUERKJU on 10.05.2023.
//
#include <stdlib.h>
#include "time.h"


int give_rand_num(int max_num){
    // Seed the random number generator with the current time
    srand(time(0)* time(0));


    return rand() % max_num;
}

void double_num(char *numbers){
    f

    for (int i = 0; i < sizeof(numbers); ++i) {
        numbers[i] = numbers[i]*2;
    }
}