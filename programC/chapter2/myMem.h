#ifndef _MY_MEM_H
#define _MY_MEM_H

#include <stdio.h>
#include <malloc.h>

void* mAlloc(int size);
void mFree(void* ptr);
int mSize(void* ptr);

#endif