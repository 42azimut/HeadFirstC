#include <stdio.h>

struct exercise{
    const char *discrpition;
    float       duration; 
};

struct meal{
    const char *ingredient;
    float       weight;
};

struct preference{
    struct meal food;
    struct exercise exercise;
};

struct fish{
    const char *name;
    const char *species;
    int         teeth;
    int         age;
    struct preference care;
};


void label(struct fish a){
    printf("이름: %s\n품종: %s\n이빨수: %i\n나이: %i\n", a.name, a.species, a.teeth, a.age);
    printf("%2.2f파운드의 %s를 먹이고 %2.2f시간동안 %s하게 하세요!!\n", 
    a.care.food.weight, a.care.food.ingredient, a.care.exercise.duration, a.care.exercise.discrpition);
}

int main(){
    struct fish snappy = {"snappy", "piranya", 48, 12, {{"meat", 0.2}, {"거품수족관에서 수영", 7.5}}};
    label(snappy);
    return 0;
}


