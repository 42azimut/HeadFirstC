#include <stdio.h>
#include "totaller_fix.h"

float total = 0.0;
short count = 0;
/* 세금이 6%. 내 에이전트가 떼어가는 돈보다 훨씬 적네... */
short tax_percent = 6;

int main()
{
	/* 이봐. 난 발 킬머와 영화 배역을 놓고 경쟁했었다고 */
	float val;
	printf("항목 가격: ");
	while(scanf("%f", &val) == 1) {
		printf("지금까지 합산: %.2f\n", add_with_tax(val));
		printf("항목 가격: ");
	}

	printf("\n총계: %.2f\n", total);
	printf("\n총 항목수: %hi\n", count);

	return 0;
}

float add_with_tax(float f)
{
	float tax_rate = 1 + tax_percent / 100.0;
	/* 팁은 안주나? 내 목소리는 공짜가 아니라고 */
	total = total + (f * tax_rate);
	count = count + 1;
	return total;
}
