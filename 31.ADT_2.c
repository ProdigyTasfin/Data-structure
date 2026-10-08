#include <stdio.h>

void removeAt(int A[], int *end, int pos)
{
    for (int i = pos; i < *end; i++)
    {
        A[i] = A[i + 1];
    }

    (*end)--;
}

int main(void)
{
    int A[5] = {10, 15, 20, 30, 40};
    int end = 4;

    removeAt(A, &end, 1);

    for (int i = 0; i <= end; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nend = %d\n", end);

    return 0;
}