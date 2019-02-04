// page 78, 79 : commit 2019 Lunar New Year :)
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include "myArray1D.h"

// Function static : just only using in this file
static int sz_nItem;
static int sz_sizeItem;
static int headSize = sizeof(sz_nItem) + sizeof(sz_sizeItem);
static int memSize(int nItem, int sizeItem)
{
    if (sizeItem < 0)
    {
        sizeItem = -sizeItem;
    }
    if (sizeItem == 0)
    {
        sizeItem = 1;
    }
    if (nItem < 0)
    {
        nItem = -nItem;
    }
    return headSize + nItem * sizeItem;
}

static void* origin_addr(void* aData) // Calculate root address, when allocate
{
    if (aData)
    {
        return (char*)aData - headSize;
    }
    return NULL;
}

static void* data_addr(void* origin) //Calculate range address begin data
{
    if (origin)
    {
        return ((char*)origin + headSize);
    }
    return NULL;
}

static void* nItem_addr(void* aData)
{
    return origin_addr(aData);
}

static void* sizeItem_addr(void* aData)
{
    if (aData)
    {
        return (char*)aData - sizeof(sz_sizeItem);
    }
    return NULL;
}
// ---------------------End function static---------------------

void* arrInit(int nItem, int sizeItem)
{
    void* aOrigin = NULL;
    void* aData = NULL;
    int sz = memSize(nItem, sizeItem);
    aOrigin = malloc(sz);
    if (aOrigin)
    {
        memset(aOrigin, 0, sz);
        aData = data_addr(aOrigin);
        *(int*)nItem_addr(aData) = nItem;
        *(int*)sizeItem_addr(aData) = sizeItem;
    }
    return aData;
}

int arrSize(void* aData)
{
    if (aData)
    {
        return *(int*)nItem_addr(aData);
    }
    return 0;
}

int arrItemSize(void* aData)
{
    if (aData)
    {
        return *(int*)sizeItem_addr(aData);
    }
    return 0;
}

void* arrPushBack(void* aData, void* x)
{
    int nItem = arrSize(aData);
    int szItem = arrItemSize(aData);
    void* aNew = arrResize(aData, nItem + 1);
    if (aNew)
    {
        memcpy((char*)aNew + nItem*szItem, x, szItem);
        aData = aNew;
    }
    return aData;
}

void* arrResize(void* aData, int nItem)
{
    int sz;
    int sizeItem;
    void* aNew = NULL;
    void* aOrigin = NULL;
    if (!aData || nItem < 0)
    {
        return NULL;
    }
    aOrigin = origin_addr(aData);
    sizeItem = *(int*)sizeItem_addr(aData);
    sz = memSize(nItem, sizeItem);
    aNew = realloc(aOrigin, sz);
    if (aNew)
    {
        aData = data_addr(aNew);
        *(int*)nItem_addr(aData) = nItem;
        return aData;
    }
    return NULL;
}

void* arrPopBack(void* aData)
{
    int nItem = arrSize(aData);
    int szItem = arrItemSize(aData);
    void* x = NULL;
    if (aData && nItem > 0)
    {
        nItem--;
        x = (char*)aData + nItem*szItem;
        *(int*)nItem_addr(aData) = nItem;
    }
    return x;
}

void arrFree(void* aData)
{
    if (aData)
    {
        free(origin_addr(aData));
    }
}
//////////////////////////////////////////////

// void main()
// {

// }