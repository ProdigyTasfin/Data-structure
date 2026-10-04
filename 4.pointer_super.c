// PREDICT THE ANSWER

#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 9;

    int *p = &a;
    int *q = &b;

    *p = *q;

    printf("a = %d\n", a);
    printf("p = %p\n", (void*)p);
    printf("b = %d\n", b);
    printf("q = %p\n", (void*)q);

    p = q;

    *p = 20;

    printf("a = %d\n", a);
    printf("p = %p\n", (void*)p);
    printf("b = %d\n", b);
    printf("q = %p\n", (void*)q);

    return 0;
}

// Answer: 9 9 9 20

/*AFTER RUNNING IT IS VERY CLEAR 

a = 9
p = 000000E1221FF85C
b = 9
q = 000000E1221FF858
a = 9
p = 000000E1221FF858
b = 20
q = 000000E1221FF858

Here p and q's address is same which is pointing to b and re-enter the value and change the b's value! */