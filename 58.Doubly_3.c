#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create first node
struct Node *addToEmpty(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        return head;
    }

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;

    return head;
}

// Add node at the end
struct Node *addAtEnd(struct Node *head, int data)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        return head;
    }

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    // Start from first node
    struct Node *ptr = head;

    // Find the last node
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // Connect old last node to new node
    ptr->next = temp;

    // Connect new node backward to old last node
    temp->prev = ptr;

    return head;
}

// Create the entire list
struct Node *createList(struct Node *head)
{
    int n;
    int data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        return head;
    }

    // Input first node
    printf("Enter node 1: ");
    scanf("%d", &data);

    head = addToEmpty(head, data);

    // Input remaining nodes
    for (int i = 2; i <= n; i++)
    {
        printf("Enter node %d: ", i);
        scanf("%d", &data);

        head = addAtEnd(head, data);
    }

    return head;
}

// Print forward
void printList(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main(void)
{
    struct Node *head = NULL;

    head = createList(head);

    printf("Doubly Linked List: ");
    printList(head);

    return 0;
}