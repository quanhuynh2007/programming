#include <iostream>
#include <vector>
using namespace std;

void arrayFloatOutput(const vector<float> &a)
{
    for(int i = 0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void arrayFloatInput(vector<float> &a)
{
    float x;
    while (cin >> x)
    {
        a.push_back(x);
    }
}

int main()
{   
    vector<float> a;
    cout << "Input an array, press Ctrl X then Enter to stop:" << endl;
    arrayFloatInput(a);
    cout << "Element(s) in the array: ";
    arrayFloatOutput(a);
    cout << endl;
    return 0;
}