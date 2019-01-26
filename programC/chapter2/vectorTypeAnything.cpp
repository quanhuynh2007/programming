#include <iostream>
#include <vector>
using namespace std;

template <class T>
void intarrayMake(vector<T> &a, T elements[], int n) // Create array
{
    int i = 0;
    a.resize(0);
    while (i < n)
    {
        a.push_back(elements[i]);
        i++;
    }
}

template <class T>
void intarrayOut(vector<T> &a, ostream &outDev) // Print Array
{
    for (int i = 0; i < a.size(); i++)
    {
        outDev << a[i] << " ";
    }
    outDev << endl;
}

template <class T>
void intarrayCat(vector<T> &dest, vector<T> &src) // Merge Array
{
    int size1 = dest.size(), size2 = src.size();
    int idx = size1, newsize = size1 + size2, i = 0;
    dest.resize(newsize);
    while (i < size2)
    {
        dest[idx] = src[i];
        idx++; i++;
    }
}

template <class T>
void intarrayCutFrom(vector<T> &a, int pos, vector<T> &b) // Cut Array
{
    int size = a.size(), j = pos;
    if (j < 0 || j >= size)
    {
        return;
    }
    b.resize(0);
    while (j < size)
    {
        b.push_back(a[j]);
        j++;
    }
    a.resize(pos);
}

template <class T>
void intarrayInsert(vector<T> &a, int pos, T element) // Insert element
{
    if (pos < 0 || pos >= a.size())
    {
        return;
    }
    vector<T> b;
    intarrayCutFrom(a, pos, b);
    a.push_back(element);
    intarrayCat(a, b);
}

int main()
{
    float x[] = {3, 5, 2.5, -4.3, 9, 7, 8, 6};
    int n = sizeof(x)/sizeof(x[0]);
    vector<float> a, b, c;

    intarrayMake(a, x, n);
    cout << "a: "; intarrayOut(a, cout);
    intarrayCutFrom(a, 3, b);
    cout << "a now: "; intarrayOut(a, cout);
    cout << "b: "; intarrayOut(b, cout);
    intarrayCat(b,a);
    cout << "b now: "; intarrayOut(b, cout);
    a.pop_back();
    cout << "a now: "; intarrayOut(a, cout);
    intarrayInsert(b, 3, (float)-999.12);
    cout << "b now: "; intarrayOut(b, cout);
    return 0;
}