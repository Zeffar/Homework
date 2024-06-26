#include <stdio.h>
#include <stdlib.h>

typedef struct node // Anonymous structure
{
    int data;
    struct node *next;
} Node; // type definition

void insert(Node **head, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Aloca memorie pt un nod nou
    newNode->data = x;
    newNode->next = *head;
    *head = newNode; // mut head la capul stivei
}

void deleteNode(Node **head, int key)
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

void pop(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
    {
        return;
    }
    *head = temp->next;
    free(temp);
}

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    pop(&head);
    printList(head);

    return 0;
}
