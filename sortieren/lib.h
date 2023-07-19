//
// Created by BUERKJU on 19.07.2023.
//

#ifndef SORTIEREN_LIB_H
#define SORTIEREN_LIB_H

#include <time.h>

#define LIST_LENGTH 100000

void swap(int *a, int *b);

int *readFile(char *file_path);

int *bubblesort(int *list);

void quickSort(int arr[], int low, int high);

int partition(int arr[], int low, int high);

void print_list(int *list);

long long GetUSecClock();

#endif //SORTIEREN_LIB_H
