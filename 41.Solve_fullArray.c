#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Current maximum number of elements the array can hold
    int capacity = 4;

    // Current number of actual elements in the array
    int size = 4;

    // Allocate memory for 4 integers on the heap
    int *A = malloc(capacity * sizeof(int));

    // Check whether memory allocation was successful
    if (A == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Store initial values
    A[0] = 10;
    A[1] = 20;
    A[2] = 30;
    A[3] = 40;

    printf("Before resizing:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nCapacity = %d\n", capacity);
    printf("Size = %d\n", size);

    // Check whether the array is full
    if (size == capacity)
    {
        // Double the capacity
        capacity = capacity * 2;

        // Allocate a new, larger array
        int *newA = malloc(capacity * sizeof(int));

        // Check whether the new allocation was successful
        if (newA == NULL)
        {
            // Release the old array before exiting
            free(A);
            return 1;
        }

        // Copy all old elements into the new array
        for (int i = 0; i < size; i++)
        {
            newA[i] = A[i];
        }

        // Release the old smaller array
        free(A);

        // Make A point to the new larger array
        A = newA;
    }

    // Add the new value at the first free index
    A[size] = 50;

    // Increase the number of actual elements
    size++;

    printf("\nAfter resizing and inserting 50:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\nCapacity = %d\n", capacity);
    printf("Size = %d\n", size);

    // Release heap memory when finished
    free(A);
    A = NULL;

    return 0;
}

