#include<stdio.h>

int larger(int a, int b){
    if ( a > b)
        return a;
    return b;
}

int main(){
    int greatest;
    greatest = larger(100, 10000);
    printf("%i 가 가장 크다\n", greatest);
    return 0;
}
