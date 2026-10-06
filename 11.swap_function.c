// If we don't use pointer what will happen? Below the code what will happen? 

#include <stdio.h>

void swap(int *p, int *q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    printf("Before swapping: %d %d\n", a,b);

    swap(&a, &b);

    printf("After swapping: %d %d", a,b);

    return 0;
} 

/*
First, a = 10 and b = 20.

When we call swap(&a, &b), we do not pass the values 10 and 20.
We pass the addresses of a and b.

Inside swap(), p points to a and q points to b.

Using *p and *q, the function accesses and changes the original
values stored in a and b.

The function does not return the swapped values.
The original variables are modified directly through their addresses.
*/
