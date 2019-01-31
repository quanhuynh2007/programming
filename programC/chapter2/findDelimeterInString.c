#include <stdio.h>
#include <time.h>
#include <string.h>

int isDelimeter(char ch)
{
    return (ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n');
}

// index version 1
char* delimeterPosIndex(char* str)
{
    int i = 0, len = strlen(str);
    while (i < len && !isDelimeter(str[i]))
    {
        i++;
    }
    return str+i;
}

// index version 2
char* delimeterPosIndexV2(char* str)
{
    int i = 0;
    while (str[i] && !isDelimeter(str[i]))
    {
        i++;
    }
    return str+i;
}

// index version 3
char* delimeterPosIndexV3(char* str)
{
    int i = 0;
    char ch;
    while ((ch = str[i]) && !isDelimeter(ch))
    {
        i++;
    }
    return str+i;
}

char* delimeterPosPointer(char* str)
{
    char* p = str;
    while (*p && !isDelimeter(*p))
    {
        p++;
    }
    return p;
}

void main()
{
    char s1[] = "167810123456781012345678101234567810123456781012345678101234567810123456781012343456781,0";

    clock_t t;
    double time_taken;
    int i;
    char* posIndex;
    char* posPointer;

    for (i = 0; i < 1; i++)
    {
        t = clock();
        posPointer = delimeterPosPointer(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Pointer = %f\n", time_taken);

        t = clock();
        posIndex = delimeterPosIndex(s1);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("index   = %f\n", time_taken);
    }
    printf("\n");
    printf("index   pos = %ld\n", posIndex - s1);
    printf("Pointer pos = %ld\n", posPointer - s1);
    printf("%c %c\n", *posIndex, *posPointer);
    printf("%p %p\n", posIndex, posPointer);
}