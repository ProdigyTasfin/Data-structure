#include <stdio.h>

int get(int A[], int *end, int pos)
{
    // Check whether the requested index is valid
    if (pos < 0 || pos > *end)
    {
        printf("Invalid position\n");
        return -1;
    }

    // Return the value stored at the requested index
    return A[pos];
}

int main(void)
{
    int A[5] = {10, 20, 30};
    int end = 2;

    int value = get(A, &end, 0);

    printf("Value = %d\n", value);

    return 0;
}