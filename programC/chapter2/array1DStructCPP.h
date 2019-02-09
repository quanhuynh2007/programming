#ifndef _FLOAT_ARRAY_H
#define _FLOAT_ARRAY_H

#include <malloc.h>
#include <stdlib.h>
struct floatArray
{
    int n;
    float* members;
    float dummy;
    float& operator[](int n);
};

void floatArrayOutput(floatArray& a);
#endif