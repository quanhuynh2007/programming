#include "myMem.h"

void* mAlloc(int size)
{
    size += sizeof(int);
    void *ptr = malloc(size);
    *(int*)ptr = size;
    return ((int*)ptr) + 1;
}

void mFree(void* ptr)
{
    ptr = ((int*)ptr) - 1;
    free(ptr);
}

int mSize(void* ptr)
{
    return *(((int*)ptr) - 1);
}

int main()
{
    float* a = NULL;
    a = (float*)malloc(100 * sizeof(float));
    printf("mSize : %d\n", mSize(&a));
    printf("a = %p\n", a);
    printf("*a = %f\n", *a);
    printf("&a = %p\n", &a);
    if (!a)
    {
        printf("Mem error!\n");
        return -1;
    }
    
    printf("%ld %ld\n", sizeof(int), sizeof(a));
    if (a)
    {
        printf("free\n");
        free(a);
    }
    printf("Hello\n");
    return 0;
}