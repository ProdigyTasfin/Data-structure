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

    // Check whether memory allocation succeeded
    if (head == NULL)
    {
        return 1;
    }

    // Store value in the first node
    head->data = 45;

    // Currently there is no next node
    head->link = NULL;


    // Create the second node
    struct node *n2 = malloc(sizeof(struct node));

    if (n2 == NULL)
    {
        free(head);
        return 1;
    }

    // Store value in second node
    n2->data = 98;

    // Currently second node is the last node
    n2->link = NULL;

    // Connect first node to second node
    head->link = n2;


    // Create the third node
    struct node *n3 = malloc(sizeof(struct node));

    if (n3 == NULL)
    {
        free(n2);
        free(head);
        return 1;
    }

    // Store value in third node
    n3->data = 3;

    // Third node is the final node
    n3->link = NULL;

    // Connect second node to third node
    n2->link = n3;


    // Print values by following the links
    printf("%d\n", head->data);
    printf("%d\n", head->link->data);
    printf("%d\n", head->link->link->data);


    // Release all heap memory
    free(n3);
    free(n2);
    free(head);

    return 0;
}