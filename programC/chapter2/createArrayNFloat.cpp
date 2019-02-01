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

float* arrayFloatInput(int& n)
{
    cin >> n;
    if (n <= 0)
    {
        cout << "Number of array is INVALID!!!" << endl;
        return NULL;
    }
    float* a = new float[n];
    if (a)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    return a;
}

int main()
{
    float *bArray;
    int numB;
    cout << "Number and elements: ";
    bArray = arrayFloatInput(numB);
    if (bArray)
    {
        // Do something here...
        arrayFloatOutput(bArray, numB);
        // Free allocated memory
        delete[] bArray;
    }
    return 0;
}