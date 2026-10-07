#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = (int *)malloc(sizeof(int));

    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 25;

    printf("%d\n", *p);

    free(p);
    p = NULL;

    return 0;
}