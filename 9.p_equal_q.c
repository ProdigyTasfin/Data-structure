
// if p = q, what will happen here? Predict the output! 

#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 10;

    int *p = &a;
    int *q = &b;

    p = q;

    *p = 30;

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", *p);
    printf("%d\n", *q);

    return 0;
}

// Output: 5 30 30 30 ... Firstly a = 5 and b = 10 and then declared two pointers point to variables' then p and q are both equal to
// its address, so now p is now getting b's address, then *p change to 30, that means b also change to 30, a remains same 5