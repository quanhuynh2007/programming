#include <stdio.h>

void UpperCase(unsigned char *pCh)
{
    if (*pCh >= 'a' && *pCh <= 'z')
    {
        *pCh = (*pCh) - 32;
    }
}

void main()
{
    unsigned char ch;
    printf("Input a character: ");
    scanf("%c", &ch);
    UpperCase(&ch);
    printf("After to to UpperCase: %c\n", ch);
}