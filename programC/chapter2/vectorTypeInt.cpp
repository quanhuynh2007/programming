#include <iostream>
#include <vector>
using namespace std;
// Modify to test push
void intarrayMake(vector<int> &a, int elements[], int n) // Create array
{
    int i = 0;
    a.resize(0);
    while (i < n)
    {
        a.push_back(elements[i]);
        i++;
    }
}

void intarrayOut(vector<int> &a, ostream &outDev) // Print Array
{
    for (int i = 0; i < a.size(); i++)
    {
        outDev << a[i] << " ";
    }
    outDev << endl;
}

void intarrayCat(vector<int> &dest, vector<int> &src) // Merge Array
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

void intarrayCutFrom(vector<int> &a, int pos, vector<int> &b) // Cut Array
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

void intarrayInsert(vector<int> &a, int pos, int element) // Insert element
{
    if (pos < 0 || pos >= a.size())
    {
        return;
    }
    vector<int> b;
    intarrayCutFrom(a, pos, b);
    a.push_back(element);
    intarrayCat(a, b);
}

int main()
{
    int x[] = {3, 5, 2, 4, 9, 7, 8, 6};
    int n = sizeof(x)/sizeof(x[0]);
    vector<int> a, b, c;

    intarrayMake(a, x, n);
    cout << "a: "; intarrayOut(a, cout);
    intarrayCutFrom(a, 3, b);
    cout << "a now: "; intarrayOut(a, cout);
    cout << "b: "; intarrayOut(b, cout);
    intarrayCat(b,a);
    cout << "b now: "; intarrayOut(b, cout);
    a.pop_back();
    cout << "a now: "; intarrayOut(a, cout);
    intarrayInsert(b, 3, 999);
    cout << "b now: "; intarrayOut(b, cout);
    return 0;
}