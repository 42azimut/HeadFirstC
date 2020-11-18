#include<stdio.h>
#include<stdlib.h>

int main(){
    char card_name[3];
    
    int count = 0;
    while (card_name[0] != 'X'){
        
        puts("카드를 입력하사에요: ");
        scanf("%2s", card_name);
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
        case 'X':
            break;
        default:
            val = atoi(card_name);
            if ((val< 1) || (val > 11)){
                puts("카드를 다시 입력하세요!");
                continue;
            }
        }
        if ((val > 2) && (val < 7)){
            count ++;
        } else if (val == 10){
            count --;
        }
        printf("현재 카운트: %i\n", count);
    }
    return 0;
}
