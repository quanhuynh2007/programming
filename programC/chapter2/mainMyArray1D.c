#include "myArray1D.h"
#include <stdio.h>
#pragma pack(1) // need to deep understand
typedef struct
{
    int numerator; // the number above the line in a common fraction showing how many of the parts indicated by the denominator are taken, for example, 2 in 2/3.
    int denominator;
} fraction;
void fractionPrint(fraction f)
{
    if (f.numerator == 0 || f.denominator == 1)
    {
        printf("%d ", f.numerator);
    }
    else
    {
        printf("%d/%d ", f.numerator, f.denominator);
    }
}
void fractionArrOut(fraction* f)
{
    int i;
    int n = arrSize(f); // waiting ...
    for (i = 0; i < n; i++)
    {
        fractionPrint(f[i]);
    }
}
fraction* fractionArrInput()
{
    fraction* a = (fraction*)arrInit(0, sizeof(fraction));
    fraction* anew;
    fraction f;
    while (scanf("%d %d", &(f.numerator), &(f.denominator)) > 0)
    {
        anew = (fraction*)arrPushBack(a, &f);
        if (anew)
        {
            a = anew;
        }
    }
    return a;
}

void main()
{
    fraction* B;
    fraction* q;
    printf("Input elements:\n");
    B = fractionArrInput();
    // Do something here...
    printf("%d element(s):\n", arrSize(B));
    fractionArrOut(B);
    q = (fraction*)arrPopBack(B);
    printf("\nAfter pop:\n");
    fractionArrOut(B);
    if (q)
    {
        printf("\nPop Item: ");
        fractionPrint(*q);
    }
    printf("\n");
    // Free allocated memory
    arrFree(B);
}