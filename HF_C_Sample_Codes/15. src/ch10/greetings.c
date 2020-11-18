#include <stdio.h>

int main()
{
	char name[30];
	printf("이름을 입력하세요: ");
	fgets(name, 30, stdin);
	printf("안녕 %s\n", name);
	return 0;
}

