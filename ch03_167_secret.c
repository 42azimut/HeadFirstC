#include <stdio.h>

int main(){
    
    char word[10];

    int i = 0;
    while(scanf("%9s", word) == 1){
        
        i = i + 1;
        if ( i % 2 == 1)  //나머지 값이 word 순서(인덱스) 출력
            fprintf(stdout, "%s\n", word); //1번쨰, 
        else if ( i % 2 == 0) // 나머지가 2로 나눠 나머지 0인 순서(짝수 인덱스) 에러출력!
            fprintf(stderr, "%s\n", word);
    }
    return 0;
}