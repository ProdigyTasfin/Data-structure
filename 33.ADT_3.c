#include <stdio.h>

int isEmpty(int end)
{
    // If end is -1, there is no valid element in the list
    if (end == -1)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    // -1 means the list is currently empty
    int end = -1;

    if (isEmpty(end))
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List is not empty\n");
    }

    return 0;
}