#include <stdio.h>

int search(int A[], int *end, int val)
{
    // Check every valid element from left to right
    for (int i = 0; i <= *end; i++)
    {
        if (A[i] == val)
        {
            // Return the index when the value is found
            return i;
        }
    }

    // Return -1 if the value does not exist
    return -1;
}

int main(void)
{
    int A[5] = {10, 20, 30, 40};
    int end = 3;

    int val;

    printf("Enter the value: ");
    scanf("%d", &val);

    int index = search(A, &end, val);

    printf("Index = %d\n", index);

    return 0;
}