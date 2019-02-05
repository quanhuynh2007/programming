// page 81 : commit 2019 Lunar New Year - second day : C/C++
#ifndef _MY_ARRAY_T_H
#define _MY_ARRAY_T_H
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

// Function static : just only using in this file
static int dummy_nItem;
static int sizeof_nItem = sizeof(dummy_nItem);
template <class T>
static void* origin_addr(T* aData) // Calculate root address, when allocate
{
    return (char*)aData - sizeof_nItem;
}

template <class T>
static T* data_addr(T* origin) //Calculate range address begin data
{
    return (T*)((char*)origin + sizeof_nItem);
}

template <class T>
static void set_nItem(T* aData, int nItem) // Update number of array
{
    *(int*)origin_addr(aData) = nItem;
}

template <class T>
static int get_nItem(T* aData) // Read number of array
{
    return *(int*)origin_addr(aData);
}
// ---------------------End function static---------------------

template <class T>
bool arrResize(T* &aData, int nItem)
{
    int sz = sizeof_nItem + nItem * sizeof(T);
    T* aNew = NULL;
    T* originAddr = NULL;
    if (aData)
    {
        originAddr = origin_addr(aData);
    }
    aNew = (T*)realloc(originAddr, sz);
    if (aNew)
    {
        if (!aData) // First allocation
        {
            memset(aNew, 0, sz);
        }
        aData = data_addr(aNew);
        set_nItem(aData, nItem);
        return true;
    }
    return false;
}

template <class T>
int arrSize(T* aData)
{
    if (aData)
    {
        return get_nItem(aData);
    }
    return 0;
}

template <class T>
void arrFree(T* aData)
{
    if (aData)
    {
        free(origin_addr(aData));
    }
}

template <class T>
bool arrPushBack(T* &aData, T x)
{
    int nItem = arrSize(aData);
    if (arrResize(aData, 1 + nItem))
    {
        memset(&aData[nItem], 0, sizeof(T));
        aData[nItem] = x;
        return true;
    }
    return false;
}

template <class T>
T arrPopBack(T* &aData)
{
    int nItem = arrSize(aData);
    T x;
    if (aData && nItem > 0)
    {
        nItem--;
        x = aData[nItem];
        set_nItem(aData, nItem);
    }
    return x;
}

#endif