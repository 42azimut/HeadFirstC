#include <stdio.h>

struct preference{
    const char *food;
    float exercise_hours;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preference care;
};



void catalog(struct fish f){
    /* data */
    printf("%s는 %s종이고, 이빨이 %i개 이고, %i살 입니다\n", f.name, f.species, f.teeth, f.age);
}

void label(struct fish f){
    printf("이름 : %s\n종 : %s\n이빨수 : %i\n나이 : %i살\n", f.name, f.species, f.teeth, f.age);
}

int main(){
    struct fish snappy = {"스내피", "피라냐", 69, 4, {"meat", 6.5}};
    struct fish jay = snappy;
    catalog(snappy);
    label(jay);
    //printf("이름: %s\n", snappy.name);
    printf("스내피는 %s를 먹어요\n", snappy.care.food);
    printf("스내피는 %.2f 시간동안 운동한다\n", snappy.care.exercise_hours);
    printf("제이는 %s를 먹네요\n", jay.care.food);
    return 0;

}


