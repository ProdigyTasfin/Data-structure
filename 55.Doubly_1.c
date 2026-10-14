#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *addToEmpty(struct Node *head, int data)
{
    // Create a new node
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        return head;
    }

    // No previous node
    temp->prev = NULL;

    // Store data
    temp->data = data;

    // No next node
    temp->next = NULL;

    // New node becomes the first node
    head = temp;

    return head;
}

int main(void)
{
    struct Node *head = NULL;

    head = addToEmpty(head, 45);

    printf("%d\n", head->data);

    return 0;
}