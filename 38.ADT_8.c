#include <stdio.h>

#define MAX_SIZE 5

void append(int A[], int *end, int val)
{
    // Check whether the array is already full
    if (*end == MAX_SIZE - 1)
    {
        printf("Array is full\n");
        return;
    }

    // Move end to the next free index
    (*end)++;

    // Store the new value at the new end position
    A[*end] = val;
}

int main(void)
{
    int A[MAX_SIZE];
    int end = -1;

    append(A, &end, 10);
    append(A, &end, 20);
    append(A, &end, 30);

    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nend = %d\n", end);

    return 0;
}