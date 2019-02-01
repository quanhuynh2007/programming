#ifndef _CREATE_ARRAY_TYPE_ANYTHING_TEMPLATE_H
#define _CREATE_ARRAY_TYPE_ANYTHING_TEMPLATE_H

#include <malloc.h>
#include <iostream>
using namespace std;

template<class T>
void arrPushBack(T* &a, int &n, T x)
{
    int m = n + 1;
    T* anew = (T*)realloc(a, m * sizeof(T));
    if (anew)
    {
        anew[n] = x;
        n++;
        a = anew;
    }
}

template<class T>
void arrInput(T* &a, int &n)
{
    T x;
    a = NULL;
    n = 0;
    while (cin >> x)
    {
        arrPushBack(a, n, x);
    }
}

template<class T>
void arrOutput(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

#endif // End of File