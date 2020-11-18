#include<stdio.h>

int main(){
    
    /*int contestants[] = {1,2,3};*/
    char contestants[] = "abcdefg hijk";
    char *choice = contestants;
    printf("first %p\n", contestants);
    contestants[0] = 'z';
    printf("second %c\n", contestants[1]);
    contestants[1] = contestants[2];
    printf("third %c\n", contestants[1]);

    contestants[2] = *choice;
    printf("4th %c\n", contestants[2]);
    printf("5th %p\n", &contestants);
    printf("6th *choice : %c  ///  choice : %p\n", *choice, choice);

    int i = 0;
    while (contestants[i] != '\0' ){
        printf("%c", i[contestants]);  /* contestants[i] */
        i++;
    }
    printf("\n");
    return 0;

}