#include "createArrayTypeAnythingTemplate.h"
struct fraction
{
    int numerator; // the number above the line in a common fraction showing how many of the parts indicated by the denominator are taken, for example, 2 in 2/3.
    int denominator;
};

ostream& operator<< (ostream& outDev, const fraction& fr)
{
    if (fr.denominator == 1 || fr.numerator == 0)
    {
        outDev << fr.numerator;
    }
    else
    {
        outDev << fr.numerator << "/" << fr.denominator;
    }
    return outDev;
}

istream& operator>> (istream& inDev, fraction& fr)
{
    inDev >> fr.numerator >> fr.denominator;
    return inDev;
}

int main()
{
    fraction *fr;
    int numFr;
    cout << "Input elements of array:" << endl;
    arrInput(fr, numFr);
    // Do something here...
    cout << numFr << "element(s):" << endl;
    if (fr)
    {
        arrOutput(fr, numFr);
        //Free allocated memory
        free(fr);
    }
    return 0;
}