#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int index; 
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->index = index;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        newNode->prev = q->rear;
        q->rear = newNode;
    }
}

int dequeueFront(Queue* q, int* index) {
    if (q->front == NULL) return -1;

    Node* temp = q->front;
    int value = temp->value;
    *index = temp->index;
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    } else {
        q->front->prev = NULL;
    }
    free(temp);
    return value;
}

int dequeueRear(Queue* q, int* index) {
    if (q->rear == NULL) return -1; 
    Node* temp = q->rear;
    int value = temp->value;
    *index = temp->index;
    q->rear = q->rear->prev;
    if (q->rear == NULL) { 
        q->front = NULL;
    } else {
        q->rear->next = NULL;
    }

    free(temp);
    return value;
}

void freeQueue(Queue* q) {
    while (q->front != NULL) {
        int tempIndex;
        dequeueFront(q, &tempIndex);
    }
    free(q);
}

int main() {
    Queue* queue = createQueue();
    int input, steps, maxSum = 0;
    int selected[100], order[100], positions[100]; 
    int index = 1; 


    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        enqueue(queue, input, index);
        index++;
    }


    scanf("%d", &steps);

    for (int i = 0; i < steps; i++) {
        int frontIndex, rearIndex;
        int front = dequeueFront(queue, &frontIndex);
        int rear = dequeueRear(queue, &rearIndex);

        if (rear > front) {
            maxSum += rear; 
            selected[i] = rear;
            order[i] = 2;
            positions[i] = rearIndex;
        } else {
            maxSum += front; 
            selected[i] = front;
            order[i] = 1; 
            positions[i] = frontIndex;
        }
    }

    printf("%d\n", maxSum);

    for (int i = 0; i < steps; i++) {
        if (order[i] == 1)
            printf("%d %d\n", selected[i], positions[i]);
        else
            printf("%d %d\n", selected[i], positions[i]);
    }
    freeQueue(queue);

    return 0;
}
