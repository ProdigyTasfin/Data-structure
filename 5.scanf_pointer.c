#include <stdio.h>

int main(void)
{
    int a;
    int *p = &a;

    printf("ENTER: ");
    scanf("%d", p);

    printf("%d\n", a);
    printf("%d\n", *p);

    return 0;
}