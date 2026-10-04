#include <stdio.h>

int main(){


int a, b, r;

int *p, *q;

p = &a;
q = &b;

scanf("%p", (void*)p);
scanf("%d", q);

r = (*p) * (*q);

printf("%d\n", r);


return 0;
}