// Predict the output 

#include <stdio.h>

int main(void)
{
    int a[4] = {10, 20, 30, 40};
    int *p = a;

    printf("%d\n", *p);
    printf("%d\n", *(p + 1));
    printf("%d\n", *(p + 2));
    printf("%d\n", *(p + 3));

    return 0;
}

//OUTPUT 10 20 30 40 *p = a is 0 index then +1 1st index increase by 4bytes 