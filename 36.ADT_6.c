#include <stdio.h>

void set(int A[], int *end, int pos, int val)
{
    // Check whether the requested index is valid
    if (pos < 0 || pos > *end)
    {
        printf("Invalid position\n");
        return;
    }

    // Replace the old value with the new value
    A[pos] = val;
}

int main(void)
{
    int A[5] = {10, 20, 30};
    int end = 2;

    printf("Before: %d %d %d\n",
           A[0], A[1], A[2]);

    set(A, &end, 1, 99);

    printf("After:  %d %d %d\n",
           A[0], A[1], A[2]);

    return 0;
}