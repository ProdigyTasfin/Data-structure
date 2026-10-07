/*
#include<stdio.h>
#include<stdlib.h>

int main(){


int *p = malloc(sizeof(int));

*p = 50;

//free(p); it will print something like -1110363904 value

printf("NOW: %d\n", *p);

free(p);
    p = NULL;

    printf("SEE THE VALUE AFTER FREE IT: %d\n", *p);

    return 0;

} */

// SAEF 

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int));

    if (p == NULL)
    {
        return 1;
    }

    *p = 50;

    printf("NOW: %d\n", *p);

    free(p);
    p = NULL;

    if (p == NULL)
    {
        printf("p is NULL now. Cannot dereference it.\n");
    }

    return 0;
}