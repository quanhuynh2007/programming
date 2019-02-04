// page 76
#ifndef _MY_ARRAY1D_H
#define _MY_ARRAY1D_H

void* arrInit(int nItem, int sizeItem);
void* arrResize(void* a, int nItem);
int arrSize(void* a);
void arrFree(void* a);
void* arrPushBack(void* a, void* x);
void* arrPopBack(void* a);

#endif