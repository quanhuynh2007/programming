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

float* floatArPushBack(float* a, int* n, float x)
{
    int m = (*n) + 1;
    float* anew = (float*)realloc(a, m * sizeof(float));
    if (anew)
    {
        anew[*n] = x;
        (*n)++;
    }
    return anew;
}

float* arrayFloatInput(int* n)
{
    float* anew;
    float* a = NULL;
    float x;
    *n = 0;
    while (scanf("%f", &x) > 0)
    {
        anew = floatArPushBack(a, n, x);
        if (anew)
        {
            a = anew;
        }
    }
    return a;
}

void main()
{
    float *bArray;
    int numB;
    printf("Input elements:\n");
    bArray = arrayFloatInput(&numB);
    if (bArray)
    {
        // Do something here...
        printf("%d element(s): ", numB);
        arrayFloatOutput(bArray, numB);
        // Free allocated memory
        free(bArray);
    }
}