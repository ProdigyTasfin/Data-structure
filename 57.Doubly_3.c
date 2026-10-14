#include <stdio.h>
#include <stdlib.h>

// ADD AT END 

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create first node in an empty list
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

// Insert a node at the end
struct Node *addAtEnd(struct Node *head, int data)
{
    // If list is empty
    if (head == NULL)
    {
        return addToEmpty(head, data);
    }

    // Create new node
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        return head;
    }

    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    // Start from first node
    struct Node *ptr = head;

    // Move to the last node
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // Old last node points forward to new node
    ptr->next = temp;

    // New node points backward to old last node
    temp->prev = ptr;

    return head;
}

// Print forward
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

    head = addToEmpty(head, 34);
    head = addAtEnd(head, 45);
    head = addAtEnd(head, 9);

    printForward(head);

    return 0;
}