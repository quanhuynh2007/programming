#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int n;
    float* members;
} floatArray;

void floatArrayInit(floatArray* a, int n)
{
    a->n = n;
    a->members = (float*)calloc(n, sizeof(float));
}

void floatArrayInput(floatArray* a)
{
    int m;
    if (!a)
    {
        printf("Memeory Error!!!\n");
        return;
    }
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("Number of array is INVALID!!!\n");
        return;
    }
    floatArrayInit(a, m);
    if (a->members)
    {
        int i;
        for (i = 0; i < m; i++)
        {
            scanf("%f", &a->members[i]);
        }
    }
}

void floatArrayFree(floatArray* a)
{
    if (a && a->members)
    {
        free(a->members);
    }
}

void floatArrayOutput(floatArray* a)
{
    int i;
    if (a && a->members)
    {
        for (i = 0; i < a->n; i++)
        {
            printf("%f\t", a->members[i]);
        }
        printf("\n");
    }
}

void main()
{
    floatArray bArray;
    printf("Number and elements: ");
    floatArrayInput(&bArray);
    // Do something here...
    printf("Array is : ");
    floatArrayOutput(&bArray);
    // Free allocated memory
    floatArrayFree(&bArray);
}