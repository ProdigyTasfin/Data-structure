int g = 10;      // Global

void test()
{
    int x = 20;  // Stack

    int *p = malloc(sizeof(int)); // p = Stack
    *p = 30;                      // pointed memory = Heap

    free(p);
}