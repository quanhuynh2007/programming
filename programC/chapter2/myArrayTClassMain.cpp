#include "myArrayTClass.h"
#include <iostream>
using namespace std;

#pragma pack(1)
typedef struct
{
    int numerator;
    int denominator;
} fraction;

fraction* fractionArrInput()
{
    fraction* a = NULL;
    fraction f;
    while (cin >> f.numerator >> f.denominator)
    {
        arrPushBack(a, f);
    }
    return a;
}

void fractionPrint(fraction f)
{
    if (f.numerator == 0 || f.denominator == 1)
    {
        cout << f.numerator << " ";
    }
    else
    {
        cout << f.numerator << "/" << f.denominator << " ";
    }
}

void fractionArrOut(fraction* f)
{
    int n = arrSize(f);
    for (int i = 0; i < n; i++)
    {
        fractionPrint(f[i]);
    }
}

int main()
{
    printf("Hello My Array T Class Template\n");
    fraction* B;
    fraction q;
    printf("Input elements:\n");
    B = fractionArrInput();
    // Do something here...
    printf("%d element(s):\n", arrSize(B));
    fractionArrOut(B);

    q = arrPopBack(B);
    printf("\nAfter pop:\n");
    fractionArrOut(B);
    printf("\nPop Item: ");
    fractionPrint(q);

    // Free allocated memory
    arrFree(B);
    return 0;
}