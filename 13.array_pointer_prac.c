#include <stdio.h>

int main(void)
{
    int a[5] = {3, 8, 2, 7, 6};
    int *p = a;

    printf("%d\n", *p);
    printf("%d\n", *(p + 3));
    printf("%d\n", *p + 3);

    return 0;
}

// output 3 7 6