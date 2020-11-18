#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coeff)
{
	printf("몸무게: %3.2f 파운드\n", weight);
	printf("거리: %3.2f 마일\n", distance);
	printf("칼로리 소비: %4.2f Cal\n", coeff * weight * distance);
}

