//TRAVERSAL 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main(void)
{
    // Create first node
    struct node *head = malloc(sizeof(struct node));

    // Create second node
    struct node *n2 = malloc(sizeof(struct node));

    // Create third node
    struct node *n3 = malloc(sizeof(struct node));

    // Store data
    head->data = 45;
    n2->data = 98;
    n3->data = 3;

    // Connect the nodes
    head->link = n2;
    n2->link = n3;
    n3->link = NULL;

    // Temporary pointer used for traversal
    struct node *ptr = head;

    // Counter for number of nodes
    int count = 0;

    // Traverse until ptr becomes NULL
    while (ptr != NULL)
    {
        count++;

        // Move ptr to the next node
        ptr = ptr->link;
    }

    printf("Count = %d\n", count);

    // Free allocated memory
    free(n3);
    free(n2);
    free(head);

    return 0;
}