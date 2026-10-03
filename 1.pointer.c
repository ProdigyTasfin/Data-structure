#include <stdio.h>

int main() {

    int a = 5;
    int b;
    int *p;

    p = &a;

    printf("a = %d\n", a);
    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);
    printf("&a = %p\n", (void*)&a);

    p = &b;
    *p = 5;

    printf("b = %d\n", b);
    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);
    printf("&b = %p\n", (void*)&b);

    return 0;
}