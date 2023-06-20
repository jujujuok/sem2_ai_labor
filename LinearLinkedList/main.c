#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedListCell.h"


int main() {
    LinListCell *anchor = NULL;
    LinListCell *cell;

    // 1) Beliebig viele Strings (bis 255 Zeichen Länge) einliest.
    while (1) {
        // einlesen
        char string[255];
        printf("\nEnter String, <! to stop reading in>: ");
        scanf("%254s", string);
        //TODO: leere Eingabe

        if (strcmp(string, "!") == 0) { break; }

        // Zu Liste hinzufügen
        cell = LinListAllocCell(string);
        printf("%s -- payload", cell->payload);

        LinListInsertFirst(&anchor, cell);

        LinListPrint(anchor);
    }

    // ----- Funktionen testen -----
    // --- Test ExtractFirst
    //LinListCell *first = LinListExtractFirst(&anchor);
    //free(first);

    // --- Test LinListFreeCell
    /*
    printf("Enter a string to remove from the list: ");
    char string_to_remove[255];
    scanf("%254s", string_to_remove);
    LinListCell *current = anchor;
    while (current != NULL) {
        if (strcmp(current->payload, string_to_remove) == 0) {
            LinListFreeCell(&anchor, current);
            break;
        }
        current = current->next;
    }
    printf("List after removing the element:\n");
    LinListPrint(anchor);
    */



    // Woche 3
    /*LinListExtractLast(&anchor);
    LinListPrint(anchor);

    cell = LinListAllocCell("insert last");
    LinListInsertLast(&anchor, cell);
    LinListPrint(anchor);*/

    LinListRemoveDuplicates(&anchor);
    LinListPrint(anchor);


    // Test Free List
    LinListFree(&anchor);
    LinListPrint(anchor);
    free(cell);
    return 0;
}




/*    LinListInsertFirst(anchor, LinListAllocCell("test"));
    LinListInsertFirst(anchor, LinListAllocCell("test2"));
    LinListInsertFirst(anchor, LinListAllocCell("test3"));


    //Freigeben eines Elementes / Löschen eines Elements
    LinListCell *junkcell = anchor->next->next; //for testing
    LinListFreeCell(anchor, junkcell);*/