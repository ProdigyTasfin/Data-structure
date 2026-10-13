#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main(void)
{
    // Create existing nodes
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

    // Value and position to insert
    int value = 99;
    int pos = 1;

    // Create the new node
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        return 1;
    }

    // Store the new value
    new_node->data = value;
    new_node->link = NULL;

    // Special case: insert at position 1
    if (pos == 1)
    {
        // New node points to old first node
        new_node->link = head;

        // New node becomes the first node
        head = new_node;
    }
    else
    {
        // Start from the first node
        struct node *ptr = head;

        // Move ptr to position (pos - 1)
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->link;
        }

        // New node points to the old next node
        new_node->link = ptr->link;

        // Previous node now points to new node
        ptr->link = new_node;
    }

    // Print the updated linked list
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);

        // Move to the next node
        ptr = ptr->link;
    }

    printf("\n");

    return 0;
}

