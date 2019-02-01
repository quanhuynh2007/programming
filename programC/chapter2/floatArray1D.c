#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include "floatArray1D.h"

// Function static : just only using in this file -------- page 72
static int dummy_nItem;
static int headSize = sizeof(dummy_nItem);
static int memSize(int nItem) // Size : plus more bytes head
{
    if (nItem < 0)
    {
        nItem = -nItem;
    }
    return headSize + nItem * sizeof(float);
}

static void* origin_addr(float* aData) // Calculate root address, when allocate
{
    return (char*)aData - headSize;
}

static void* data_addr(void* origin) //Calculate range address begin data
{
    return (float*)((char*)origin + headSize);
}

static void set_nItem(float* aData, int nItem) // Update number of array
{
    *(int*)origin_addr(aData) = nItem;
}

static int get_nItem(float* aData) // Read number of array
{
    return *(int*)origin_addr(aData);
}
// ---------------------End function static---------------------

float* floatArrResize(float* aData, int nItem)
{
    int sz = memSize(nItem);
    float* aNew = NULL;
    void* originAddr = NULL;
    if (aData)
    {
        originAddr = origin_addr(aData);
    }
    aNew = (float*)realloc(originAddr, sz);
    if (aNew)
    {
        if (!aData) // First allocation
        {
            memset(aNew, 0, sz);
        }
        aData = (float*)data_addr(aNew); // support C++
        set_nItem(aData, nItem);
    }
    return aData;
}

int floatArrSize(float* aData)
{
    if (aData)
    {
        return get_nItem(aData);
    }
    return 0;
}

void floatArrFree(float* aData)
{
    if (aData)
    {
        free(origin_addr(aData));
    }
}

float* floatArrPushBack(float* aData, float x)
{
    int nItem = floatArrSize(aData);
    float* aNew = floatArrResize(aData, nItem + 1);
    if (aNew)
    {
        aNew[nItem] = x;
        aData = aNew;
    }
    return aData;
}

float floatArrPopBack(float* aData)
{
    int nItem = floatArrSize(aData);
    float x = 0;
    if (aData && nItem > 0)
    {
        nItem--;
        x = aData[nItem];
        set_nItem(aData, nItem);
    }
    return x;
}

// void main()
// {

// }