#include<stdio.h>

int main(){
    char name[40];
    printf("이름을 입력하세요: ");
    scanf("%39s", name);
    printf("%c\n", name[5]);

    int age;
    printf("나이는? : ");
    scanf("%i", &age);
    

    char first_name[20];
    char last_name[20];
    puts("성 과 이름을 입력 : ");
    scanf("%19s %19s", first_name, last_name);
    printf("성은 %s, 이름은 %s\n", first_name, last_name);

    int i = 0;
    while (first_name[i] != '\0'){
        printf("%c", first_name[i]);
        i++;
    }
    printf("\n");
    return 0;
}