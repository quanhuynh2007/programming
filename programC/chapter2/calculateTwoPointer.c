#include <stdio.h>

int main()
{
    long a[10];
    void* ptr1 = &a[7];
    void* ptr2 = &a[1];
    long d0 = ptr1 - ptr2; // Book note Compile Error (nosize), but I compile okay, d0 = 48
    printf("d0 = %ld %ld %ld\n", d0, sizeof(long), sizeof(int));

    long d1 = (long*)ptr1 - (long*)ptr2;
    long d2 = (char*)ptr1 - (char*)ptr2;
    long d3 = (short*)ptr2 - (short*)ptr1;
    printf("d1 = %ld\n", d1);
    printf("d2 = %ld\n", d2);
    printf("d3 = %ld\n", d3);
    printf("Distance = %ld\n", (long)ptr1 - (long)ptr2);
    // long d4 = (long*)ptr1 - (char*)ptr2; // Error (different types)
    // long d5 = (long*)ptr1 - (float*)ptr2; // Error (different types)
    return 0;
}