#include <stdio.h>
#include "sort_lib.h"


int main(int argc, char *args[]) {

    long long time, time1, time2;





    int listlen = 10;

    time = GetUSecClock();
    int *list_bubble = readFile(args[1]);
    printf("%s", "--- Reading in: ---");
    printf("%lld us", GetUSecClock()-time);
    int *list_quick = readFile(args[1]);

    // print unsorted
    printf("%s", "--- Unsorted: ---");
    print_list(list_bubble);

    //BUBBLESORT
    time1 = GetUSecClock();
    printf("\n%s", "--- Bubblesort: ---");
    print_list(bubblesort(list_bubble));
    printf("Bubble sort took %lld us", GetUSecClock() - time1); //TODO STRING FORMAT

    //QUICKSORT
    printf("\n%s", "--- Quicksort: ---");
    print_list(quicksort(0, listlen-1, list_quick));
    printf("Bubble sort took %lld us", GetUSecClock() - time1);

    return 0;
}


