// Tell or predict the output

#include <stdio.h>

int main(void)
{
    int x = 10;
    int *ptr = &x;

    printf("%d\n", x);
    printf("%d\n", *ptr);

    *ptr = 50;

    printf("%d\n", x);
    printf("%d\n", *ptr);

    return 0;
}

// Answer: 10 10 50 50