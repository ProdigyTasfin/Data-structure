#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int capacity = 4;
    int size = 4;

    int *A = malloc(capacity * sizeof(int));

    A[0] = 10;
    A[1] = 20;
    A[2] = 30;
    A[3] = 40;

    // Array is full
    capacity = capacity * 2;

    int *newA = malloc(capacity * sizeof(int));

    // Copy old values
    for (int i = 0; i < size; i++)
    {
        newA[i] = A[i];
    }

    // Release old array
    free(A);

    // A now points to new bigger array
    A = newA;

    // Insert new value
    A[size] = 50;
    size++;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    free(A);

    return 0;
}