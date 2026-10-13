#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *insertBeginning(struct node *head, int value)
{
    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        return head;
    }

    // Store data
    new_node->data = value;

    // Point new node to the old first node
    new_node->link = head;

    // Move head to the new first node
    head = new_node;

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
    struct node *head = NULL;

    head = insertBeginning(head, 30);
    head = insertBeginning(head, 20);
    head = insertBeginning(head, 10);

    printList(head);

    return 0;
}