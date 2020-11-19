#include <stdio.h>

typedef struct {
    const char  *name;
    const char  *species;
    int         age;
} turtle;

void happy_birthday(turtle *t)
{
    t->age = t->age + 1;  //(*t).age == t->age
    printf("happy birth day!! %s~ your age is now %i.\n", t->name, t->age);
}

int main()
{
    turtle myrtle = {"GGobuki", "장수거북", 99};
    happy_birthday(&myrtle);
    printf("%s나이는 이제 %i살입니다.\n", myrtle.name, myrtle.age);
    return 0;
}

