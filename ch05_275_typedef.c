#include <stdio.h>

typedef struct {
    float       tank_capacity;
    int         tank_psi;
    const char  *suit_material;
} equip;

typedef struct scuba{
    const char  *name;
    equip   kit;
} diver;

void badge(diver d){
    printf("이름: %s 수족관: %2.2f (%i), 잠수복재질: %s\n", 
    d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);
}

int main(){
    diver jayden = {"Jayden", {5.5, 4000, "neoflan"}};
    badge(jayden);
    return 0;
}