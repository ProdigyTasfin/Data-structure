#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Insert a new node at the end of the linked list
struct node *insertEnd(struct node *head, int value)
{
    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));

    // Check whether memory allocation succeeded
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    // Store the value in the new node
    new_node->data = value;

    // New node will initially be the last node
    new_node->link = NULL;

    // If the list is empty,
    // new node becomes the first node
    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    // Start traversal from the first node
    struct node *ptr = head;

    // Stop when ptr reaches the last node
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    // Connect the old last node to the new node
    ptr->link = new_node;

    // Return the first node of the list
    return head;
}

// Print all nodes
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

// Free all allocated nodes
void freeList(struct node *head)
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        // Save next node before freeing current node
        struct node *next = ptr->link;

        free(ptr);

        // Move to the saved next node
        ptr = next;
    }
}

int main(void)
{
    // Start with an empty linked list
    struct node *head = NULL;

    // Insert values at the end
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 50);

    // Print the linked list
    printList(head);

    // Release heap memory
    freeList(head);

    return 0;
}