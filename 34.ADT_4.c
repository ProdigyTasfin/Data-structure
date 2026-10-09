#include <stdio.h>

int sizeList(int end)
{
    // end stores the last valid index
    // Therefore, total elements = end + 1
    return end + 1;
}

int main(void)
{
    int A[5] = {10, 20, 30};

    // Last valid element is A[2]
    int end = 2;

    printf("Size = %d\n", sizeList(end));

    return 0;
}