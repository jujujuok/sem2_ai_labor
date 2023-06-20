#include <stdio.h>
#include <stdlib.h>
#include "rand_num.h"


int main(int argc, char *argv[])
{
    int MAX_NUM = 1000;
    FILE *in = stdin;


    printf("%d", give_rand_num(MAX_NUM));

    return 0;
}