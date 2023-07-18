//
// Created by BUERKJU on 19.07.2023.
//

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int *readFile(char *file_path) {
    int *list = malloc(sizeof(int) * LIST_LENGTH);

    FILE *fptr = fopen(file_path, "r");

    if (fptr == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", file_path);
        exit(EXIT_FAILURE);
    }

    int row = 0;
    char line[100];
    while (fgets(line, sizeof(line), fptr)) {
        char *ptr;
        long num = strtol(line, &ptr, 10);
        list[row] = num;
        row++;
    }

    if (fclose(fptr) != 0) {
        fprintf(stderr, "Error: could not close file '%s'\n", file_path);
        exit(EXIT_FAILURE);
    }
    return list;
}

int *bubblesort(int *list) {
    int i, j, temp;

    for (i = 0; i < LIST_LENGTH - 1; i++) {
        for (j = 0; j < LIST_LENGTH - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    return list;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print_list(int *list) {
    for (int i = 0; i < LIST_LENGTH; ++i) {
        printf("%d\n", list[i]);
    }
}


long long GetUSecClock() {
    clock_t cputime = clock();
    return (long long) cputime * 1000000 / CLOCKS_PER_SEC;
}

