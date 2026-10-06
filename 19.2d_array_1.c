#include <stdio.h>

int main(void)
{
    int B[3][2] = {
        {5, 10}, 
        {15, 20}, 
        {25, 30} 
    };

    printf("%d\n", *(*(B + 0) + 1));
    printf("%d\n", *(*(B + 1) + 0));
    printf("%d\n", *(*(B + 2) + 1));

    return 0;
}

// OUTPUT: 10 15 30