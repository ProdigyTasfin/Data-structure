// Q: User gives length and width, you have to answer the area through pointer and scanf. 

#include <stdio.h>

int main () {

    int a,b;
    int *p, *q;

    p = &a;
    q = &b;

    printf("Enter Length: ");
    scanf("%d", p);
    printf("Enter Width: ");
    scanf("%d", q);


    int r = (*p) * (*q);

    printf("Area: %d", r);
    

    return 0;
}