#include <stdio.h>
#include "floatArray1D.h"

void floatArrOut(float* a)
{
    int i;
    int n = floatArrSize(a);
    for (i = 0; i < n; i++)
    {
        printf("%f ", a[i]);
    }
}

float* floatArrInput()
{
    float* anew;
    float* a = NULL;
    float x;
    while (scanf("%f", &x) > 0)
    {
        anew = floatArrPushBack(a, x);
        if (anew)
        {
            a = anew;
        }
    }
    return a;
}

void main()
{
    float *b;
    float x;
    printf("Input elements:\n");
    b = floatArrInput();
    // Do something here...
    printf("%d element(s):\n", floatArrSize(b));
    floatArrOut(b);

    x = floatArrPopBack(b);
    printf("\nAfter pop:\n");
    floatArrOut(b);
    printf("Pop element: %f\n", x);

    // floatArrPushBack(b, x);
    // printf("\nAfter Push back:\n");
    // floatArrOut(b);
    // Free allocated memory
    floatArrFree(b);

}