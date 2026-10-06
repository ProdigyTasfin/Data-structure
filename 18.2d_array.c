// Predict the answer

#include <stdio.h>

int main(void)
{
    int B[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    printf("%d\n", B[0][1]);
    printf("%d\n", *(*(B + 1) + 0));
    printf("%d\n", *(*(B + 1) + 2));

    return 0;
}

// OUTPUT 20 40 60 think like a row increased by B+1