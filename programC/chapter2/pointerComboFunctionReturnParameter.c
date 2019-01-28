#include <stdio.h>
#include <string.h>

char* strMax(char* str1, char* str2)
{
    if (strcmp(str1, str2) > 0)
    {
        return str1;
    }
    return str2;
}

int main()
{
    const int maxLen = 256;
    char s1[maxLen], s2[maxLen];
    printf("Input s1 = "); gets(s1);
    printf("Input s2 = "); gets(s2);
    // warning: the `gets' function is dangerous and should not be used ==> maybe using fgets()
    //printf("Result: %s\n", strupr(strMax(s1, s2))); strupr undefined, I don't know why...
    printf("Result: %s\n", strMax(s1, s2));
    return 0;
}