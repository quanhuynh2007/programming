#include <iostream>
#include <malloc.h>
using namespace std;

struct floatArray
{
    int n;
    float* members;
};

void floatArrayInit(floatArray& a, int n)
{
    a.n = n;
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
            cin >> a.members[i];
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

void floatArrayOutput(floatArray& a)
{
    if (a.members)
    {
        for (int i = 0; i < a.n; i++)
        {
            cout << a.members[i] << "\t";
        }
        cout << endl;
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