#include <stdio.h>
#include <math.h>

void swap(float* x, float* y)
{
    float u = *x;
    *x = *y;
    *y = u;
}

void ajust(float* x, float* y)
{
    if (fabs(*x) > fabs(*y))
    {
        //swap(x, y);
        swap(&(*x), &(*y));
    }
}

void main()
{
    float a = -1864.5F, b = 273.9F;
    ajust(&a, &b);
    printf("New values of a and b now are a = %.1f, b = %.1f\n", a, b);
}