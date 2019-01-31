#include <memory.h>
#pragma pack(1)

// C
template <class T>
void initData(T* dat)
{
    memset(dat, 0, sizeof(T));
}
// C++
template <class T>
void initData(T& dat)
{
    memset(&dat, 0, sizeof(T));
}

typedef struct
{
    char* name;
    char* familyName;
    long id;
    char birthDate[11];
    float agp;
} studentRec;

int main()
{
    studentRec stu1, stu2;
    initData(&stu1);
    initData(stu2);
    return 0;
}