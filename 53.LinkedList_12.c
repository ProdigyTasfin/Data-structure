#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *deleteAtPosition(struct node *head, int pos)
{
    // Case 1: List is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Invalid position
    if (pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }

    // Case 3: Delete the first node
    if (pos == 1)
    {
        // Save the first node
        struct node *temp = head;

        // Move head to the second node
        head = head->link;

        // Delete the old first node
        free(temp);

        return head;
    }

    // previous starts at position 1
    struct node *previous = head;

    // current starts at position 2
    struct node *current = head->link;

    int currentPos = 2;

    // Move current until it reaches the target position
    while (current != NULL && currentPos < pos)
    {
        previous = current;
        current = current->link;

        currentPos++;
    }

    // If current becomes NULL, position does not exist
    if (current == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    // Skip the node that will be deleted
    previous->link = current->link;

    // Delete the target node
    free(current);

    return head;
}

void printList(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    printf("\n");
}

void freeList(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        struct node *next = ptr->link;

        free(ptr);

        ptr = next;
    }
}

int main(void)
{
    // Create four nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));
    struct node *n4 = malloc(sizeof(struct node));

    // Store data
    head->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;

    // Connect the nodes
    head->link = n2;
    n2->link = n3;
    n3->link = n4;
    n4->link = NULL;

    printf("Before deletion: ");
    printList(head);

    // Delete position 3
    head = deleteAtPosition(head, 3);

    printf("After deletion: ");
    printList(head);

    // Release remaining memory
    freeList(head);

    return 0;
}