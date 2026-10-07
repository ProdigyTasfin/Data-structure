#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = calloc(4, sizeof(double));

    if (arr == NULL)
    {
        return 1;
    }

    arr[1] = 10;
    arr[3] = 30;

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}

//OUTPUT: 0 10 0 30