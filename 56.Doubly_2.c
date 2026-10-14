#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create the first node in an empty list
struct Node *addToEmpty(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        return head;
    }

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;

    return head;
}

// Insert a new node at the beginning
struct Node *addAtBeginning(struct Node *head, int data)
{
    // If list is empty, create the first node
    if (head == NULL)
    {
        return addToEmpty(head, data);
    }

    // Create a new node
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        return head;
    }

    // Store data
    temp->data = data;

    // New node has no previous node
    temp->prev = NULL;

    // New node points forward to the old first node
    temp->next = head;

    // Old first node points backward to the new node
    head->prev = temp;

    // New node becomes the first node
    head = temp;

    return head;
}

// Print list forward
void printForward(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main(void)
{
    struct Node *head = NULL;

    // First node
    head = addToEmpty(head, 45);

    // Insert 34 before 45
    head = addAtBeginning(head, 34);

    printForward(head);

    return 0;
}