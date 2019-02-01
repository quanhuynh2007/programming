#ifndef _MY_ARRAY1D_H
#define _MY_ARRAY1D_H

float* floatArrResize(float* a, int nItem);     // similar resize() of type Vector
int floatArrSize(float* a);                     // similar size()
void floatArrFree(float* a);
float* floatArrPushBack(float* a, float x);     // similar push_back()
float floatArrPopBack(float* a);                // similar pop_back()

#endif