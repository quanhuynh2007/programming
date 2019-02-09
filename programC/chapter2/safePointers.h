// very Hard, page 84
#ifndef _SAFE_POINTERS_H
#define _SAFE_POINTERS_H
#include <malloc.h>
#include <stdio.h>
#include <memory.h>

void* safeMalloc(size_t szmem);
int checkPtr(void* pdata);
size_t safeSize(void* pdata);
void safeFree(void* pdata);
void* safeRealloc(void* pdata, size_t szmem);

#endif