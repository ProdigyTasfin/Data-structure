#include <stdio.h>

int main(void)
{
    int a[4] = {10, 20, 30, 40};
    int *p = a;

    printf("%d\n", *p);

    (*p)++;

    printf("%d\n", *p);

    p++;

    printf("%d\n", *p);

    printf("%d\n", *(p + 1));

    return 0;
}

// OUTPUT: 10 11 20 30