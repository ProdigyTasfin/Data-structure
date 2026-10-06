// Predict 

#include <stdio.h>

int main(void)
{
    int B[2][3] = {
        {5, 10, 15},
        {20, 25, 30}
    };

    int (*p)[3] = B;

    printf("%d\n", p[0][2]);
    printf("%d\n", p[1][0]);
    printf("%d\n", *(*(p + 1) + 1));

    return 0;
}

// 0,0 -> 5 0,1 -> 10, 0,2 -> 15
// 1,0 -> 20 1,1 -> 25 1,2 -> 30 

// Output 15 20 25 