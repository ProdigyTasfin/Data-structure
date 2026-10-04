// TWO POINTERS

#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    int *p = &a; // P POINTING TO A'S VALUE
    int *q = &b;

    printf("%d\n", *p);
    printf("%d\n", *q);

    *p = 50;
    *q = 80;

    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}