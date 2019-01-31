#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; float* a = NULL;
    printf("Enter array size: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid size!");
        return 1;
    }
    a = (float*)malloc(n*sizeof(float));
    if (a == NULL)
    {
        printf("Mem error!");
        return 1;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }
    printf("Data: ");
    for (i = 0; i < n; i++)
    {
        printf("%f ", a[i]);
    }
    printf("\n");
    // do some other things ...
    // Finally freeing memory
    free(a);
    return 0;
}