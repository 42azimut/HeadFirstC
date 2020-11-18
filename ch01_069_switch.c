#include<stdio.h>
#include<stdlib.h>

int main(){
    
    char card_name[3];
    puts("카드를 입력하세요!");
    scanf("%s", card_name);

    int val = 0;
    switch(card_name[0]){
    case 'K':
    case 'Q':
    case 'J':
        val = 10;
        break;
    case 'A':
        val = 11;
        break;
    default:
        val = atoi(card_name);
    }
    printf("카드는 : %i\n", val);
    return 0;

}