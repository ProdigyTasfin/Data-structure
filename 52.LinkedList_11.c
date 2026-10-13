#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Delete the last node
struct node *deleteLast(struct node *head)
{
    // Case 1: List is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    // Case 2: Only one node exists
    if (head->link == NULL)
    {
        free(head);
        head = NULL;

        return head;
    }

    // ptr will move to the last node
    struct node *ptr = head;

    // prev will stay one node behind ptr
    struct node *prev = head;

    // Traverse until ptr reaches the last node
    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }

    // prev is now the second-last node
    // Make it the new last node
    prev->link = NULL;

    // Delete the old last node
    free(ptr);

    // Avoid dangling pointer
    ptr = NULL;

    return head;
}

// Print the linked list
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

int main(void)
{
    // Create three nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));

    // Store data
    head->data = 45;
    n2->data = 98;
    n3->data = 3;

    // Connect nodes
    head->link = n2;
    n2->link = n3;
    n3->link = NULL;

    printf("Before deletion: ");
    printList(head);

    // Delete the last node
    head = deleteLast(head);

    printf("After deletion: ");
    printList(head);

    return 0;
}