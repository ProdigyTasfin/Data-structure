// Tell me, which segment is refert to globalValue, x, and, a

#include <stdio.h>

int globalValue = 50;

void test(void)
{
    int x = 10;

    printf("%d\n", x);
}

int main(void)
{
    int a = 20;

    test();

    printf("%d\n", a);
    printf("%d\n", globalValue);

    return 0;
}

// global variable is globalVarable 
// stack is x, 
// stack is a.