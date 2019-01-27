#include <stdio.h>

void swap(float* x, float* y)
{
    float u = *x;
    *x = *y;
    *y = u;
}

void main()
{
    float a = 186, b = 273;
    swap(&a, &b);
    printf("New value of a and b now are a = %f, b = %f\n", a, b);
}