#include <stdio.h>
#include <malloc.h>

void arrayFloatOutput(float a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%f\t", a[i]);
    }
    printf("\n");
}

float* arrayFloatInput(int* n)
{
    float* a = NULL;
    int m;
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("Number of array is INVALID!!!\n");
        return NULL;
    }
    *n = m;
    a = (float*)calloc(m, sizeof(float));
    if (a)
    {
        int i;
        for (i = 0; i < m; i++)
        {
            scanf("%f", &a[i]);
        }
    }
    return a;
}

void main()
{
    float *bArray;
    int numB;
    printf("Number and elements: ");
    bArray = arrayFloatInput(&numB);
    if (bArray)
    {
        // Do something here...
        arrayFloatOutput(bArray, numB);
        // Free allocated memory
        free(bArray);
    }
}