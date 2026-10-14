#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Reverse the doubly linked list
struct Node *reverseList(struct Node *head)
{
    struct Node *current = head;
    struct Node *temp = NULL;

    while (current != NULL)
    {
        // Save old previous pointer
        temp = current->prev;

        // Old next becomes new prev
        current->prev = current->next;

        // Old prev becomes new next
        current->next = temp;

        // Current node may become the new head
        head = current;

        // Move to the old next node
        // After swapping, old next is now current->prev
        current = current->prev;
    }

    return head;
}

// Print list forward
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

int main(void)
{
    // Create three nodes
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    // Store data
    head->data = 34;
    n2->data = 45;
    n3->data = 9;

    // Connect nodes
    head->prev = NULL;
    head->next = n2;

    n2->prev = head;
    n2->next = n3;

    n3->prev = n2;
    n3->next = NULL;

    printf("Before reverse: ");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("After reverse: ");
    printList(head);

    return 0;
}