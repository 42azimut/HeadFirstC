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

	printf("카드 값은 다음과 같습니다: %i\n", val);

	return 0;
}

