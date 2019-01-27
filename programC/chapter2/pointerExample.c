#include<stdio.h>
void main()
{
    float x; unsigned short a[10] = { 0 };
    unsigned short* pshort; unsigned long* plong; void* p;

    pshort = a;     // similar with p = &a[0]
    *pshort = 5;    // similar with a[0] = 5
    pshort = &a[2];
    *pshort = 19;   // similar with a[2] = 19

    p = &x;
    *(float*)p = 1.5F;  //similar with x = 1.5
    p = &a[8];
    *(unsigned short*)p = 23;   // similar with a[8] = 23
    plong = (unsigned long*)&a[5];
    *plong = 0XDEADBEEF;        // effect both a[5]BEEF=0X and a[6]=0xDEAD
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\t%hu\n", i, a[i]);
    }
}