#include <stdio.h>

void removeAt(int A[], int *end, int pos)
{
    // Check whether the requested position is valid
    if (pos < 0 || pos > *end)
    {
        printf("Invalid position\n");
        return;
    }

    // Shift all later elements one position to the left
    for (int i = pos; i < *end; i++)
    {
        A[i] = A[i + 1];
    }

    // Reduce the last valid index
    (*end)--;
}

int main(void)
{
    int A[5] = {5, 10, 15, 20, 25};
    int end = 4;

    removeAt(A, &end, 2);

    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nend = %d\n", end);

    return 0;
}