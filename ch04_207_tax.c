#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "totaller_fix.h"

//float add_with_tax(float f);

float total = 0.0;
short count = 0;
short tax_percent = 6;


int main(){
    float val;
    printf("항목 가격 : ");
    while (scanf("%f", &val) == 1){
        printf("지금까지 합산 : %.2f\n", add_with_tax(val));
        printf("항목 가격 : ");
    }
    printf("\n총계 : %.2f\n", total);
    printf("\n총 항목수: %hi\n", count);
    puts("===================================");

    printf("INT_MAX 값은 %i입니다.\n", INT_MAX);
    printf("INT_MIN 값은 %i입니다.\n", INT_MIN);
    printf("int 형은 %li바이트 입니다.\n", sizeof(int));

    printf("FLT_MAX 값은 %f입니다.\n", FLT_MAX);
    printf("FLT_MIN 값은 %.100f입니다.\n", FLT_MIN);
    printf("float형은  %li바이트 입니다.\n", sizeof(float));
    return 0;
}

float add_with_tax(float f){
    float tax_rate = 1.0 + tax_percent / 100.0;
    total = total + (f * tax_rate);
    count = count + 1;
    return total;
}