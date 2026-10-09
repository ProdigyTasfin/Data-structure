//INSERT VALUE AT ANY POSITION

#include <stdio.h>

void insert(int A[], int *end, int pos, int val)
{
    // Shift elements one step to the right
    for (int i = *end; i >= pos; i--)
    {
        A[i + 1] = A[i];
    }

    // Insert new value
    A[pos] = val;

    // Update last valid index
    (*end)++;
}

int main(void)
{
    int A[5] = {10, 20, 30, 40};
    int end = 3;

    printf("Before:\n");
    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    }

    insert(A, &end, 0, 0);

    printf("\nAfter:\n");
    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nNew end = %d\n", end);

    return 0;
} 