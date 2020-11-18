#include <stdio.h>

int main(){
    char *food;
    printf("좋아하는 음식은: ");
    fgets(food, 5, stdin);
    /*printf("%i\n", sizeof(food));*/
    return 0;
}