// In the below code predicts the output 

// Input is 7 and 3

#include <stdio.h>

int main(void)
{
    int a, b;
    int *p = &a;
    int *q = &b;

    scanf("%d", &a); // taking value as 7, store it in a, write it like where a lives/ a's address
    scanf("%d", q); // taking value as 3, store it in b, write it with pointing to b, variable q

    *p = *p + 10; // pointing to a, address is written to a
    b = b + 5; // b's value

    printf("%d %d\n", a, b);

    return 0;
}

// Output 17 and 8

