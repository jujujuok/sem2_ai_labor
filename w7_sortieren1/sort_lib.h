//
// Created by BUERKJU on 26.06.2023.
//

#ifndef W7_SORTIEREN1_SORT_LIB_H
#define W7_SORTIEREN1_SORT_LIB_H

#include <time.h>

#define LIST_LENGTH 10

typedef struct heap_structure{
    int num;
    int *left;
    int *right;
} heap;

int heapsort(int *list);

void build_heap(int *list, int N, heap *root);

void swap(int *a, int *b);

int *readFile(char *file_path);

int *bubblesort(int *list);

void heapify_heap(int *list, int N, int i);

void swap_heap(int *a, int *b);

int *quicksort(int left, int right, int *list);

int quick_split(int left, int right, int *list);

void print_list(int *list);

// Return the CPU time used by the current
// process in microseconds.
long long GetUSecClock();



#endif //W7_SORTIEREN1_SORT_LIB_H
