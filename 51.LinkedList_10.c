#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Delete the first node
struct node *deleteFirst(struct node *head)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    // Save the first node
    struct node *temp = head;

    // Move head to the second node
    head = head->link;

    // Delete the old first node
    free(temp);

    // Avoid dangling pointer
    temp = NULL;

    // Return the updated head
    return head;
}

// Print the linked list
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
    // Create three nodes
    struct node *head = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));

    // Store data
    head->data = 45;
    n2->data = 98;
    n3->data = 3;

    // Connect nodes
    head->link = n2;
    n2->link = n3;
    n3->link = NULL;

    printf("Before deletion: ");
    printList(head);

    // Delete the first node
    head = deleteFirst(head);

    printf("After deletion: ");
    printList(head);

    return 0;
}