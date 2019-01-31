#include <stdio.h>

void swap(float *x, float *y)
{
    float z = *x;
    *x = *y;
    *y = z;
}

void minMaxSort(float a[], int n)
{
    int idmin = 0, idmax = 0, i;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[idmin])
        {
            idmin = i;
        }
        if (a[i] > a[idmax])
        {
            idmax = i;
        }
    }
    swap(&a[0], &a[idmin]);
    if (idmax == 0)
    {
        idmax = idmin;
    }
    swap(&a[idmax], &a[n-1]);
    if (n > 3)
    {
        float* b = &a[1];
        minMaxSort(b, n-2);
    }
}

void main()
{
    float B[] = {-9, 12.7F, 2.3F, 11, -10, -3.6F};
    int nB = sizeof(B)/sizeof(B[0]), i;
    minMaxSort(B, nB);
    for (i = 0; i < nB; i++)
    {
        printf("%f ", B[i]);
    }
    printf("\n");
}