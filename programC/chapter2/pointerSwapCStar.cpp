#include <iostream>
using namespace std;

template <class T>
void swap(T* x,T* y)
{
    T u = *x;
    *x = *y;
    *y = u;
}

template <class T>
void swapPlus(T& x,T& y)
{
    T u = x;
    x = y;
    y = u;
}

int main()
{
    float a = 186.2, b = 273;
    swap(&a, &b);
    cout << "New value of a and b now are a = " << a << " b = " << b << endl;
    swapPlus(a, b);
    cout << "Plu value of a and b now are a = " << a << " b = " << b << endl;
    swap(&a, &b);
    cout << "New value of a and b now are a = " << a << " b = " << b << endl;
    swapPlus(a, b);
    cout << "Plu value of a and b now are a = " << a << " b = " << b << endl;
    return 0;
}