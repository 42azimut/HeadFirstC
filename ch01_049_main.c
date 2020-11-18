#include<stdio.h>
#include<stdlib.h>

int main()
{
    char card_name[4]; 
    puts("put your card's name : ");
    scanf("%s", card_name);

    int card_size = 0;
    card_size = sizeof(card_name);
    printf("size :: %i\n", card_size);
    /*
    printf(sizeof(card_name));
    */

    int val = 0;
    if (card_name[1] == 'K') {
        val = 10;
    } 
    else if(card_name[0] == 'Q') {
        val = 10;
    }
    else if(card_name[0] == 'J'){
        val = 10;
    }
    else if(card_name[0] == 'A'){
        val = 11;
    }
    else{
        val = atoi(card_name);
    }
    if((val >= 3) && (val <= 6))
        printf("카운트를 하나 올립니다\n");
    else if (val == 10 )
        printf("카운트를 하나 내린다!\n");
    return 0;
}
