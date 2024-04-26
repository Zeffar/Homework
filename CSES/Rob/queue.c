#include <stdio.h>
#include <stdlib.h>
// lista si coada
typedef struct nume 
{
    int data;
    struct nume *next;
} Node; // type definition

typedef struct // Anonymous structure
{
    Node *head, *tail;
} Queue;

void push(Queue *queue, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (queue->tail == NULL)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

void pop(Queue *queue)
{
    if (queue->head == NULL)
    {
        return;
    }
    Node *temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL)
        queue->tail = NULL;
    free(temp);
}

void printQueue(Queue *queue)
{
    Node *aux = queue->head;
    while (aux != NULL)
    {
        printf("%d -> ", aux->data);
        aux = aux->next;
    }
    printf("end\n");
}

int main()
{
    Queue queue = {NULL, NULL};
    push(&queue, 8);
    push(&queue, 9);
    push(&queue, 10);
    push(&queue, 11);
    push(&queue, 12);
    push(&queue, 13);
    push(&queue, 14);

    printQueue(&queue);
    for (int i = 0; i < 15; ++i)
    {
        pop(&queue);
        printQueue(&queue);
    }

    return 0;
}