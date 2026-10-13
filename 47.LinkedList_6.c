#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main(void)
{
    // Create the first node
    struct node *head = malloc(sizeof(struct node));

    // Create the second node
    struct node *n2 = malloc(sizeof(struct node));

    // Create the third node
    struct node *n3 = malloc(sizeof(struct node));

    // Store data
    head->data = 45;
    n2->data = 98;
    n3->data = 3;

    // Connect existing nodes
    head->link = n2;
    n2->link = n3;
    n3->link = NULL;


    // Create a new node to insert at the end
    struct node *new_node = malloc(sizeof(struct node));

    // Store data in the new node
    new_node->data = 72;

    // New node will become the last node
    new_node->link = NULL;


    // Start traversal from the first node
    struct node *ptr = head;

    // Move until ptr reaches the last node
    while (ptr->link != NULL)
{
    ptr = ptr->link;
}

    // Connect the old last node to the new node
    ptr->link = new_node;


    // Print the updated linked list
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}