// Predict the answer: 

#include <stdio.h>

int main(void)
{
    int a = 25;
    float b = 4.5f;

    void *p;

    p = &a;
    printf("%d\n", *(int *)p);

    p = &b;
    printf("%.1f\n", *(float *)p);

    return 0;
}

// 25 4.5