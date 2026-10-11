#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;             // Stores the actual value
    struct Node *next;    // Stores the address of the next node
};

int main(void)
{
    // Create three nodes dynamically on the heap
    struct Node *A = malloc(sizeof(struct Node));
    struct Node *B = malloc(sizeof(struct Node));
    struct Node *C = malloc(sizeof(struct Node));

    // Check memory allocation
    if (A == NULL || B == NULL || C == NULL)
    {
        return 1;
    }

    // Store data in Node A
    (*A).data = 10; //Another way to write

    // Store data in Node B
    B->data = 20;

    // Store data in Node C
    C->data = 30;

    // Connect Node A to Node B
    // A->next stores B's address
    (*A).next = B;

    // Connect Node B to Node C
    // B->next stores C's address
    B->next = C;

    // C is the last node
    C->next = NULL;

    // head stores the address of the first node
    struct Node *head = A;

    printf("%d\n", (*head).data);
    printf("%d\n", (*((*head).next)).data);
    printf("%d\n", head->next->next->data);

    free(A);
    free(B);
    free(C);

    return 0;
}