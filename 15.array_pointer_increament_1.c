#include <stdio.h>

int main(void)
{
    int a[3] = {5, 10, 15};
    int *p = a;

    (*p)++;

    printf("%d\n", a[0]);
    printf("%d\n", *p);

    p++;

    printf("%d\n", *p);

    return 0;
}

// Output: 6 6 10