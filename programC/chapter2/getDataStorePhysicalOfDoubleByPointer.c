#include <stdio.h>

// C
// char* getBytes(double* x, int* nb)
// {
//     *nb = sizeof(double);
//     return (char*)x;
// }

// short* getWords(double* x, int* nw)
// {
//     *nw = sizeof(double)/sizeof(short);
//     return (short*)x;
// }

// C++
char* getBytes(double& x, int& nb)
{
    nb = sizeof(double);
    return (char*)&x;
}

short* getWords(double& x, int& nw)
{
    nw = sizeof(double)/sizeof(short);
    return (short*)&x;
}
///////////////////////////////////////////////

void listBytes(char bytes[], int nb)
{
    int i;
    for(i = 0; i < nb; i++)
    {
        printf("0X%X ", (unsigned char)bytes[i]);
    }
    printf("\n");
}
void listWords(short words[], int nw)
{
    int i = 0;
    for(i = 0; i < nw; i++)
    {
        printf("0X%X ", (unsigned short)words[i]);
    }
    printf("\n");
}

int main()
{
    double a = 0.01;
    char* storedBytes;
    int nb;
    short* storedWords;
    int nw;

    // C
    // printf("--------------------------------\n");
    // storedBytes = getBytes(&a, &nb);
    // listBytes(storedBytes, nb);

    // printf("--------------------------------\n");
    // storedWords = getWords(&a, &nw);
    // listWords(storedWords, nw);

    //C++
    printf("--------------------------------\n");
    storedBytes = getBytes(a, nb);
    listBytes(storedBytes, nb);

    printf("--------------------------------\n");
    storedWords = getWords(a, nw);
    listWords(storedWords, nw);
    return 0;
}