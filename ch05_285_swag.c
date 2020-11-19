#include <stdio.h>

typedef struct {
    const char  *descrpition;
    float       value;
}swag;

typedef struct {
    swag *swag;
    const char  *sequence;
}combination;

typedef struct {
    combination numbers;
    const char  *make;
}safe;

swag gold = {"Gold!", 10000.0};
combination numbers = {&gold, "3359"};

int main() {

safe s = {numbers, "dustdawn21"};
printf("내용 : %s\n", s.numbers.swag -> descrpition);
return 0;
}

