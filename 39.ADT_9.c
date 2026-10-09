#include <stdio.h>

#define MAX_SIZE 10

void insert(int A[], int *end, int pos, int val)
{
    // Check whether the insertion position is valid
    if (pos < 0 || pos > *end + 1)
    {
        printf("Invalid position\n");
        return;
    }

    // Check whether the array is already full
    if (*end == MAX_SIZE - 1)
    {
        printf("Array is full\n");
        return;
    }

    // Shift elements one position to the right
    // Start from the last valid element
    for (int i = *end; i >= pos; i--)
    {
        A[i + 1] = A[i];
    }

    // Insert the new value into the empty position
    A[pos] = val;

    // Increase the last valid index
    (*end)++;
}

int main(void)
{
    int A[MAX_SIZE] = {10, 20, 30, 40};
    int end = 3;

    insert(A, &end, 1, 15);

    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}