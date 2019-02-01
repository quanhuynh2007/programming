#include <iostream>
#include <malloc.h>
using namespace std;

void arrayFloatOutput(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

void floatArPushBack(float* &a, int &n, float x)
{
    int m = n + 1;
    float* anew = (float*)realloc(a, m * sizeof(float));
    if (anew)
    {
        anew[n] = x;
        n++;
        a = anew;
    }
}

void arrayFloatInput(float* &a, int& n)
{
    float x;
    a = NULL;
    n = 0;
    while (cin >> x)
    {
        floatArPushBack(a, n, x);
    }
}

int main()
{
    float *bArray;
    int numB;
    cout << "Input elements:" << endl;
    arrayFloatInput(bArray, numB);
    if (bArray)
    {
        // Do something here...
        cout << numB << " elements: ";
        arrayFloatOutput(bArray, numB);
        // Free allocated memory
        delete[] bArray;
    }
    return 0;
}