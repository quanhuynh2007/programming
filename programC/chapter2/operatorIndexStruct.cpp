// Page 83: 2.50
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct floatArray
{
    int n;
    float* members;
    float dummy;
    float& operator[](int i)
    {
        if (members && i >= 0 && i < n)
        {
            return members[i];
        }
        return dummy;
    }

};

void floatArrayOutput(floatArray& a)
{
    if (a.members)
    {
        for(int i = 0; i < a.n; i++)
        {
            cout << a[i] << "\t";
        }
        cout << endl;
    }

}

void floatArrayInit(floatArray& a, int n)
{
    a.n = n;
    a.dummy = 0;
    a.members = new float[n];
}

void floatArrayInput(floatArray& a)
{
    int m;
    cin >> m;
    if (m <= 0)
    {
        cout << "Number of array is INVALID!!!" << endl;
        return;
    }
    floatArrayInit(a, m);
    if (a.members)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
    }
}

void floatArrayFree(floatArray& a)
{
    if (a.members)
    {
        delete[] a.members;
    }
}

int main()
{
    floatArray bArray;
    cout << "Number and elements: ";
    floatArrayInput(bArray);
    // Do something here...
    cout << "Array is : ";
    floatArrayOutput(bArray);
    // Free allocated memory
    floatArrayFree(bArray);
    return 0;
}