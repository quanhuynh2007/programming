#include "array1DStructCPP.h"

float& floatArray::operator[] (int i)
{
    if (members && i >= 0 && i < n)
    {
        return members[i];
    }
    return dummy;
}