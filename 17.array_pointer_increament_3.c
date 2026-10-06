#include <stdio.h>

int main(void)
{
    int a[4] = {5, 10, 15, 20};

    int *p = a;

    printf("%d\n", *p);
    printf("%d\n", a[0]);
    printf("%d\n", *(a + 2));
    printf("%d\n", p[3]);

    return 0;
} 

// OUTPUT: 5 5 15 20