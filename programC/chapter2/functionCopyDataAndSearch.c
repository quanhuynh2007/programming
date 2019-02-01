#include <malloc.h>
#include <stdio.h>
#include <string.h>

// Back to future : memset(); memcpy(); _memccpy(); memmove(); memcmp(); _memicmp(); memchr() page 64
void main()
{
    const int maxLen = 256;
    char src[] = "Hello World!!!";
    printf("src = %s\n", src);
    long lenSrc = strlen(src);
    int sizeSrc = sizeof(char) * (lenSrc + 1);
    printf("src.strlen = %ld\n", lenSrc);
    printf("%ld %ld\n", sizeof(src), sizeof(src[0]));
    char *dest;
    dest = (char*)malloc(sizeSrc);
    if (!dest)
    {
        printf("Mem Error!!!\n");
        return;
    }
    memset(dest, 0, sizeSrc);
    printf("dest = %s\n", dest);
    memcpy(dest, src, sizeSrc);
    printf("dest after memcpy = %s\tsizeof(dest)=%ld\n", dest, strlen(dest) + 1);

    char *dest2;
    dest2 = (char*)malloc((strlen(dest) + 1) *sizeof(char));
    if (dest2)
    {
        memset(dest2, 0, (strlen(dest) + 1) *sizeof(char));
        printf("dest2 = %s\n", dest2);
        memcpy(dest2, dest, (strlen(dest) + 1) *sizeof(char));
        printf("dest2 after memcpy = %s\tsizeof(dest2)=%ld\n", dest2, strlen(dest2) + 1);
        free(dest2);
    }

    if (dest)
    {
        free(dest);
    }
}