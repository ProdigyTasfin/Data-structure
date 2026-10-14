#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *deleteLast(struct Node *head)
{
    // Case 1: Empty list
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;

        return head;
    }

    // Start from first node
    struct Node *temp = head;

    // Move temp to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Node before the last node
    struct Node *previous = temp->prev;

    // Second-last node becomes new last node
    previous->next = NULL;

    // Delete old last node
    free(temp);

    return head;
}

void printList(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

void freeList(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        struct Node *next = ptr->next;

        free(ptr);

        ptr = next;
    }
}

int main(void)
{
    // Create three nodes
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    // Check memory allocation
    if (head == NULL || n2 == NULL || n3 == NULL)
    {
        return 1;
    }

    // Store data
    head->data = 34;
    n2->data = 45;
    n3->data = 9;

    // Connect first node
    head->prev = NULL;
    head->next = n2;

    // Connect second node
    n2->prev = head;
    n2->next = n3;

    // Connect third node
    n3->prev = n2;
    n3->next = NULL;

    printf("Before: ");
    printList(head);

    // Delete last node
    head = deleteLast(head);

    printf("After: ");
    printList(head);

    // Free remaining nodes
    freeList(head);

    return 0;
}