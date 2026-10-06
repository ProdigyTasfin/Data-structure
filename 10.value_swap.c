// value change with pointer and function, predict the answer: 

#include <stdio.h>

void change(int *p)
{
    *p = 100;
}

int main(void)
{
    int x = 25;

    change(&x);

    printf("%d\n", x);

    return 0;
}

// OUTPUT 100