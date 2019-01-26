#include <iostream>
#include <vector>
using namespace std;

void arrayOutput(vector<float> &a)
{
    for(int i = 0; i<a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

void arrayInput(vector<float> &a)
{
    int n;
    cin >> n;
    if (n < 1)
    {
        return;
    }
    a.resize(n);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
}

int main()
{   
    vector<float> a;
    cout << "Input an array, first is the number of elements:" << endl;
    arrayInput(a);
    cout << "Element(s) in the array: ";
    arrayOutput(a);
    cout << endl;

    return 0;
}