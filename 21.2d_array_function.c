#include <stdio.h>

void change(int arr[][3])
{
    arr[0][1] = 100;
    arr[1][2] = 200;
}

int main(void)
{
    int B[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    printf("Before\n");

    printf("%d\n", B[0][1]);
    printf("%d\n", B[1][2]);

    printf("After\n");

    change(B);

    printf("%d\n", B[0][1]);
    printf("%d\n", B[1][2]);

    return 0;
}

//Output 100 200