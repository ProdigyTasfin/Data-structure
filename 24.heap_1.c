#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = malloc(sizeof(int));

    if (p == NULL)
    {
        return 1;
    }

    *p = 15;
    *p = *p + 5;

    printf("%d\n", *p);

    free(p);
    p = NULL;

    return 0;
}

// OUTPUT: 20