#include <stdio.h>
#include <time.h>

int strLengthIndex(char* str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int strLengthIndexV2(char* str)
{
    int len = 0;
    while (str[len++] != '\0');
    return len - 1;
}

int strLengthPointer(char* str)
{
    int len = 0;
    while (*str++)
    {
        len++;
    }
    return len;
}

int strLengthPointerV2(char* str) //Best, Fastest
{
    char* p = str;
    while (*p++);
    return (p - str - 1);
}

void main()
{
    char s1[] = "810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810vvvvv12345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810vvvvv123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567810123456781012345678101234567814";

    clock_t t;
    double time_taken, sumIndex = 0, sumIndexV2 = 0, sumPointer = 0, sumPointerV2 = 0, sumPointerFinal = 0;
    int i, lenIndex, lenIndexV2, lenPointer, lenPointerV2, lenPointerFinal;

    for (i = 0; i < 1; i++)
    {
        t = clock();
        lenIndex = strLengthIndex(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("index   = %f\n", time_taken);
        sumIndex += time_taken;

        t = clock();
        lenIndexV2 = strLengthIndexV2(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("index2  = %f\n", time_taken);
        sumIndexV2 += time_taken;

        t = clock();
        lenPointer = strLengthPointer(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Pointer = %f\n", time_taken);
        sumPointer += time_taken;

        t = clock();
        lenPointerV2 = strLengthPointerV2(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Pointerv2 = %f\n", time_taken);
        sumPointerV2 += time_taken;

        t = clock();
        lenPointerFinal = strLengthPointer(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("PointerFinal = %f\n\n", time_taken);
        sumPointerFinal += time_taken;
    }


    printf("%d %d %d %d %d\n", lenIndex, lenIndexV2, lenPointer, lenPointerV2, lenPointerFinal);
    printf("sumIndex : %f\tsumIndexV2 : %f\tsumPointer : %f\tsumPointerV2 : %f\tsumPointerFinal : %f\n", 
        sumIndex, sumIndexV2, sumPointer, sumPointerV2, sumPointerFinal);
}