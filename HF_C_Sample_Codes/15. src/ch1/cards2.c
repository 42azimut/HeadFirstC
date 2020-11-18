/*
 * 액면가를 계산하는 프로그램.
 * 이 코드는 베가스 공개 라이센스를 적용하여 공개합니다.
 * (c) 2014 대학 블랙잭 팀.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
	puts("카드 이름을 입력하세요: ");
	scanf("%2s", card_name);
	int val = 0;
	if (card_name[0] == 'K') {
		val = 10;
	} else if (card_name[0] == 'Q' ) {
		val = 10;	
	} else if (card_name[0] == 'J' ) {
		val = 10;	
	} else if (card_name[0] == 'A' ) {
		val = 11;	
	} else {
		val = atoi(card_name);
	}

	/* 카드 값이 3에서 6 사이인지 검사합니다 */
	if ((val > 2) && (val < 7))
		puts("카운트를 하나 올립니다");
	/* 아니면 카드가 10, J, Q, K인지 검사합니다 */
	else if (val == 10)
		puts("카운트를 하나 내립니다");

	return 0;
}

