#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *deleteFirst(struct Node *head)
{
    // Case 1: Empty list
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    // Save the old first node
    struct Node *temp = head;

    // Move head to the second node
    head = head->next;

    // If list still has a node,
    // new first node has no previous node
    if (head != NULL)
    {
        head->prev = NULL;
    }

    // Delete old first node
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

int main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    /*struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    head->data = 34;
    n2->data = 45;
    n3->data = 9;

    head->prev = NULL;
    head->next = n2;

    n2->prev = head;
    n2->next = n3;

    n3->prev = n2;
    n3->next = NULL;*/

    printf("Before: ");
    printList(head);

    head = deleteFirst(head);

    printf("After: ");
    printList(head);

    return 0;
}