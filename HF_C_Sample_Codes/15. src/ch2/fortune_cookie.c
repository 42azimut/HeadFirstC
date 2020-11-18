#include <stdio.h>

void fortune_cookie(char msg[])
{
	printf("메시지는 다음과 같습니다: %s\n", msg);
	printf("메시지는 %li 바이트 크기입니다.\n", sizeof(msg));
//	putchar(3[msg]);
}

int main()
{
	fortune_cookie("Cookies make you fat");

	return 0;
}

