//
// Created by BUERKJU on 27.06.2023.
//

#include "bestPath.h"

#include <stdbool.h>
#include <stdlib.h>
#include "library.h"


typedef struct queue_node {
    int x;
    int y;
    int distance;
    struct queue_node *next;
} QueueNode;

QueueNode* createNode(int x, int y, int distance) {
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->x = x;
    node->y = y;
    node->distance = distance;
    node->next = NULL;
    return node;
}

void enqueue(QueueNode **front, QueueNode **rear, int x, int y, int distance) {
    QueueNode *node = createNode(x, y, distance);

    if (*rear == NULL) {
        *front = *rear = node;
        return;
    }

    (*rear)->next = node;
    *rear = node;
}

QueueNode* dequeue(QueueNode **front) {
    if (*front == NULL) return NULL;

    QueueNode *temp = *front;
    *front = (*front)->next;

    return temp;
}



bool isValid(int x, int y, Lab *labyrinth) {
    return (x >= 0) && (y >= 0) && (x < labyrinth->maxrow) && (y < strlen(labyrinth->lab[x]));
}

bool isWall(int x, int y, Lab *labyrinth) {
    return labyrinth->lab[x][y] == '#';
}

bool isVisited(int x, int y, Lab *labyrinth) {
    return labyrinth->costs[x][y];
}

int findBestPath(Lab *labyrinth) {
    static const int rowNum[] = {-1, 0, 0, 1};
    static const int colNum[] = {0, -1, 1, 0};

    QueueNode *front = NULL, *rear = NULL;

    enqueue(&front, &rear, labyrinth->startx, labyrinth->starty, 0);
    labyrinth->costs[labyrinth->startx][labyrinth->starty] = 1;

    while (front != NULL) {
        QueueNode *curr = dequeue(&front);

        int x = curr->x;
        int y = curr->y;
        int distance = curr->distance;

        if (x == labyrinth->treasurex && y == labyrinth->treasurey) {
            free(curr);
            return distance;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = x + rowNum[i];
            int newCol = y + colNum[i];

            if (isValid(newRow, newCol, labyrinth) && !isWall(newRow, newCol, labyrinth) && !isVisited(newRow, newCol, labyrinth)) {
                labyrinth->costs[newRow][newCol] = 1;
                enqueue(&front, &rear, newRow, newCol, distance + 1);
            }
        }

        free(curr);
    }

    return -1;
}
