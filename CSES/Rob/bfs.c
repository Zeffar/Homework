#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node; // type definition

Node *adj[1000];
//adj -> array de 1000 de pointeri de tip Node
//adj[i] -> pointer catre lista de adiacenta a nodului i

int dist[1000];

void insertStack(Node **head, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Aloca memorie pt un nod nou
    newNode->data = x;
    newNode->next = *head;
    *head = newNode; // mut head la capul stivei
}

void deleteNodeStack(Node **head, int key)
{
    Node *temp = *head, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next; // Changed head
        free(temp);         // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void popStack(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        return;
    }
    *head = temp->next;
    free(temp);
}

void printGraph(int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d -> ", i);

        Node *node = adj[i];
        while (node != NULL)
        {
            printf("%d, ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

typedef struct
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

int empty(Queue *queue)
{
    Node *head = queue->head;
    if (head == NULL)
        return 1;
    return 0;
}

int BFS(int x, int y)
{
    Queue qe = {NULL, NULL};
    push(&qe, x);

    //vizitam nodul x
    dist[x] = 1;
    while (!empty(&qe))
    {
        int nodeIdx = qe.head->data;
        //node = queue.front();

        pop(&qe);
        Node *stackHead = adj[nodeIdx];
        while (stackHead != NULL)
        {
            int vecin = stackHead->data;
            stackHead = stackHead->next;

            if (dist[vecin] == 0)
            {
                dist[vecin] = dist[nodeIdx] + 1;
                if (vecin == y)
                {
                    return dist[vecin] - 1;
                }
                
                else
                {
                    push(&qe, vecin);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        insertStack(&adj[a], b);
    }

    printGraph(n);

    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d ", BFS(x, y));
}