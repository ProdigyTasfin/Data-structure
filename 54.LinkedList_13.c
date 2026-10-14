#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *reverseList(struct node *head)
{
    struct node *previous = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        // Save next node
        next = current->link;

        // Reverse the link
        current->link = previous;

        // Move previous forward
        previous = current;

        // Move current forward
        current = next;
    }

    // Old last node becomes new head
    head = previous;

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

int main(void)
{
    struct node *head = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));

    head->data = 10;
    n2->data = 20;
    n3->data = 30;

    head->link = n2;
    n2->link = n3;
    n3->link = NULL;

    printf("Before reverse: ");
    printList(head);

    head = reverseList(head);

    printf("After reverse: ");
    printList(head);

    return 0;
}