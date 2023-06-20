#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "LinkedListCell.h"


LinListCell *LinListAllocCell(char *payload) {
    /* Erzeugt eine Listenzelle, deren Payload eine Kopie von payload ist
    und gibt einen Pointer auf diese zurück*/
    LinListCell *cell = malloc(sizeof(LinListCell));
    cell->payload = strdup(payload);;
    cell->next = NULL;
    return cell;
}

void LinListFreeCell(LinListCell **anchor, LinListCell *junk) {
    //! "Problem": Die Liste muss zwei mal durchsucht werden.
    /* Gibt eine einzelne Listenzelle und den gespeicherten String an die
     * Speicherverwaltung zurück
     */
    if (junk == NULL || *anchor == NULL) return;

    if (*anchor == junk) {
        *anchor = junk->next;
    } else {
        LinListCell *prev = *anchor;
        while (prev->next && prev->next != junk) {
            prev = prev->next;
        }

        if (prev->next == junk) {
            prev->next = junk->next;
        } else {
            return; // junk was not found in the list
        }
    }
    free(junk->payload);
    free(junk);
}

void LinListFree(LinListCell **anchor) {
    /* Gibt die gesamte Liste mit allen Zellen an die Speicherverwaltung
     * zurück und setzt den Listenanker auf NULL
     */
    LinListCell *current = *anchor;
    while (current != NULL) {
        LinListCell *next = current->next;
        free(current->payload);
        free(current);
        current = next;
    }
    *anchor = NULL;
}

void LinListInsertFirst(LinListCell **anchor, LinListCell *newcell) {
    if (newcell == NULL) return;

    newcell->next = *anchor;
    *anchor = newcell;
}

LinListCell *LinListExtractFirst(LinListCell **anchor) {
    /*Entferne das erste Element der Liste, die bei *anchor steht
    I Voraussetzung: Die Liste ist nicht leer (sonst: Rückgabewert NULL)
    I *anchor zeigt danach auf das vormals zweite Element der Liste
    I Rückgabewert ist Pointer auf das vormals erste Element*/
    if (anchor == NULL) return NULL;

    LinListCell *first = *anchor;
    *anchor = first->next;
    first->next = NULL;
    return first;
}

void LinListPrint(LinListCell *anchor) {
    /*Gibt die gesamte Liste aus.*/
    LinListCell *current = anchor;
    int ctr = 0;

    printf("\n\n--- Liste: ---");
    while (current != NULL) {
        printf("\n%d -> %s", ctr, current->payload);
        current = current->next;
        ctr++;
    }
    printf("\n");
    if(anchor==NULL) printf("\nListe ist leer");
}

// MergeSort

LinListCell* SortedMerge(LinListCell *a, LinListCell *b) {
    LinListCell *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (strcmp(a->payload, b->payload) <= 0) {
        result = a;
        result->next = SortedMerge(a->next, b);
    } else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void FrontBackSplit(LinListCell *source, LinListCell **frontRef, LinListCell **backRef) {
    LinListCell *fast;
    LinListCell *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(LinListCell **headRef) {
    LinListCell *head = *headRef;
    LinListCell *a;
    LinListCell *b;

    if ((head == NULL) || (head->next == NULL))
        return;

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}


// Woche 3
LinListCell *LinListExtractLast(LinListCell **anchor) {
    /* Extracts the last element of the list pointed to by *anchor
     * *anchor then points to the new last element of the list
     * The return value is a pointer to the formerly last element
     */
    if (*anchor == NULL) return NULL;

    LinListCell *current = *anchor;

    while (current->next->next != NULL) {
        current = current->next;
    }
    LinListCell *last = current->next;
    current->next = NULL;

    return last;
}

void LinListInsertLast(LinListCell **anchor, LinListCell *newcell){
    LinListCell *current = *anchor;

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newcell;
}

/*
void LinListRemoveDuplicates(LinListCell **anchor) {
    LinListCell *current = *anchor;

    while (current != NULL) {
        LinListCell *find = current->next;
        while (find != NULL) {
            if (strcmp(current->payload, find->payload) == 0) {
                // remove the found duplicate!
            } else {
                find = find->next;
            }
        }
        current = current->next;
        free(find);
    }
}
*/


void LinListRemoveDuplicates(LinListCell **anchor) {
    LinListCell *current = *anchor;

    while (current != NULL) {
        LinListCell *prev_find = current;
        LinListCell *find = current->next;

        while (find != NULL) {
            if (strcmp(current->payload, find->payload) == 0) {
                prev_find->next = find->next;
                free(find->payload);
                free(find);
                find = prev_find->next;
            } else {
                prev_find = find;
                find = find->next;
            }
        }
        current = current->next;
    }
}
