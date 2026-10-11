#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;            // Stores the actual value
    struct node *link;   // Stores address of the next node
};

int main(void)
{
    // Create the first node
    struct node *head = malloc(sizeof(struct node));

    if (head == NULL)
    {
        return 1;
    }

    // Store data in the first node
    head->data = 45;
    head->link = NULL;


    // Create the second node
    struct node *current = malloc(sizeof(struct node));

    if (current == NULL)
    {
        free(head);
        return 1;
    }

    // Store data in the second node
    current->data = 98;
    current->link = NULL;

    // Connect first node to second node
    head->link = current;


    // Reuse current pointer to create the third node
    current = malloc(sizeof(struct node));

    if (current == NULL)
    {
        free(head->link);
        free(head);
        return 1;
    }

    // Store data in the third node
    current->data = 3;
    current->link = NULL;

    // Connect second node to third node
    head->link->link = current;


    // Print all values
    printf("%d\n", head->data);
    printf("%d\n", head->link->data);
    printf("%d\n", head->link->link->data);


    // Free memory
    free(head->link->link);
    free(head->link);
    free(head);

    return 0;
}