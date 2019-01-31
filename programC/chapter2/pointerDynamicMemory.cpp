#include <iostream>
using namespace std;

int main()
{
    int n; float* a = NULL;
    cout << "Enter array size: ";
    cin >> n;
    if (n < 1)
    {
        cout << "Invalid size!";
        return 1;
    }
    a = new float[n];
    if (a == NULL)
    {
        cout << "Mem error!";
        return 1;
    }
    for ( int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "Data: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    // do some other things ...
    // Finally freeing memory
    delete[] a;
    return 0;
}