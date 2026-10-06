
// Predict the answer! 

#include <stdio.h>

int main(void)
{
    int a[4] = {10, 20, 30, 40};
    int *p = a;

    printf("%d\n", *p);

    p++;
    printf("%d\n", *p);

    p++;
    printf("%d\n", *p);

    p--;
    printf("%d\n", *p);

    return 0;
}

//OUTPUT: 10 20 30 20