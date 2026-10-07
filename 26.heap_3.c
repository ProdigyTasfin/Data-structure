#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(2 * sizeof(int));

    if (arr == NULL)
    {
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;

    int *temp = realloc(arr, 4 * sizeof(int));

    if (temp == NULL)
    {
        free(arr);
        return 1;
    }

    arr = temp;

    arr[2] = 30;
    arr[3] = 40;

    printf("%d %d %d %d\n",
           arr[0], arr[1], arr[2], arr[3]);

    free(arr);
    arr = NULL;

    return 0;
}

//OUTPUT 10 20 30 40
// Here first we initialized the pointer named '*arr' then its gets some 8 bytes space and we also know if they specify
// space, it will space like array-based index, then we add temp so that previous arr not removed fully, existing indexes
// we get as well, then condition about temp == NULL, it is like error handling, whether its gives space or not!
// then arr = temp means boths address is now same! and then initialize index 2 and index 3... 