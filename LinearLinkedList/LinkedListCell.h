#ifndef LINEARLINKEDLIST_LINKEDLISTCELL_H
#define LINEARLINKEDLIST_LINKEDLISTCELL_H

#include <stdlib.h>

typedef struct lin_list {
    char *payload;
    struct lin_list *next;
} LinListCell;


LinListCell *LinListAllocCell(char *payload);
void LinListFreeCell(LinListCell **anchor, LinListCell *junk);
void LinListFree(LinListCell **anchor);
void LinListInsertFirst(LinListCell **anchor, LinListCell *newcell);
LinListCell *LinListExtractFirst(LinListCell **anchor);
void LinListPrint(LinListCell *anchor);

//Mergesort
LinListCell* SortedMerge(LinListCell *a, LinListCell *b);
void FrontBackSplit(LinListCell *source, LinListCell **frontRef, LinListCell **backRef);
void MergeSort(LinListCell **headRef);

// Woche 3
LinListCell *LinListExtractLast(LinListCell **anchor);
void LinListInsertLast(LinListCell **anchor, LinListCell *newcell);
void LinListRemoveDuplicates(LinListCell **anchor);

#endif
