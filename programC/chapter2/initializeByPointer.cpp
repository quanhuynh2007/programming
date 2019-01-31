#include <memory.h>
#pragma pack(1)
typedef struct
{
    char* name;
    char* familyName;
    long id;
    char birthDate[11];
    float agp;
} studentRec;

//C
void initialize(studentRec* st)
{
    memset(st, 0, sizeof(studentRec));
}

//C++
void initialize(studentRec& st)
{
    memset(&st, 0, sizeof(studentRec));
}

int main()
{
    studentRec stu1, stu2;
    initialize(&stu1);
    initialize(stu2);
    return 0;
}