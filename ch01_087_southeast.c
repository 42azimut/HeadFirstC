#include<stdio.h>

void go_south_east(int *lat, int *lon);

int main(){
    int latitude = 32;
    int longitude = -64;

    go_south_east(&latitude, &longitude);
    printf("그만! 현재위치 : [%i, %i]\n", latitude, longitude);
    return 0;
}

void go_south_east(int *lat, int *lon){
    printf("lat value = : %i\n", *lat);
    *lat = *lat - 1;
    *lon = *lon + 1; 
}