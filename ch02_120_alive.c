#include <stdio.h>

int main(){
    char masked_raider[] = "alive";
    char *azimut = masked_raider;
    
    printf("Masked raider %s, azimut %s\n", masked_raider, azimut);

    char *dead = "DEAD!";
    int i = 0;
    while (i < 6){
        masked_raider[i] = dead[i];
        i++;
    }
    printf("masked_raider %s, Azimut %s\n", masked_raider, azimut);
    return 0;

}