//
// Created by BUERKJU on 26.06.2023.
//

#include <stdio.h>
#include "sort_lib.h"
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

int *quicksort(int left, int right, int *list) {
    if (left > right) {
        int split = quick_split(left, right, list);
        quicksort(left, split - 1, list);
        quicksort(split + 1, right, list);
    }

    return list;
}

int quick_split(int left, int right, int *list) {
    int i = left;
    int j = right - 1;
    int pivot = list[right];

    while (i < j) {
        while (i < j & list[i] < pivot) i++;

        while (j > i && list[j] > pivot) j = j - 1;

        if (list[i] > list[j]) {
            //tausche daten[i] mit daten[j]
            int t = list[i];
            list[i] = list[j];
            list[j] = t;
        }
    }

    if (list[i] > pivot) {
        int t = list[i];
        list[i] = list[right];
        list[right] =
                t;
    } else i = right;
    return i;
}


int heapsort(int *list) {
    heap *root = malloc(sizeof(heap));
    int N = sizeof (list)/sizeof(int);
    build_heap(list, N, root);

    int size = sizeof(&list) / sizeof(int);
    while (size > 1) {
        swap_heap(list[0], size - 1);
        size--;
        heapify_heap(root);
        //assert(isHeap(root, 0))
    }
    print_list(list);
}

void build_heap(int *list, int N, heap *root) {
    // Index of last non-leaf node
    int startIdx = (N / 2) - 1;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify_heap(list, N, i);
    }
}

void print_heap(int arr[], int N)
{
    printf("Array representation of Heap is:\n");

    for (int i = 0; i < N; ++i)
        printf("%d ",arr[i]);
    printf("\n");
}

void swap_heap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_heap(int *list, int N, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < N && list[l] > list[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < N && list[r] > list[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap_heap(&list[i], &list[largest]);

        // Recursively heapify the affected sub-tree
        heapify_heap(list, N, largest);
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

