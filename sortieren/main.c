#include <stdio.h>
#include "lib.h"


int main(int argc, char *args[]) {

    long long time, time1, time2;

    time = GetUSecClock();
    int *list_bubble = readFile(args[1]);
    printf("%s\n", "--- Reading in: ---");
    printf("%lld us", GetUSecClock()-time);
    int *list_quick = readFile(args[1]);

    // print unsorted
    printf("\n%s\n", "--- Unsorted: ---");
    //print_list(list_bubble);

    //BUBBLESORT
    printf("\n%s\n", "--- Bubblesort: ---");
    time1 = GetUSecClock();
    bubblesort(list_bubble);
    //print_list();
    printf("Bubble sort took %lld us", GetUSecClock() - time1);

    //QUICKSORT
    printf("\n%s\n", "--- Quicksort: ---");
    time2 = GetUSecClock();
    quickSort(list_quick, 0, LIST_LENGTH-1);
    printf("Quicksort took %lld us", GetUSecClock() - time2);
    //print_list(list_quick);


    return 0;
}
