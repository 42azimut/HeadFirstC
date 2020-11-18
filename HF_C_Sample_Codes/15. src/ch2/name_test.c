#include <stdio.h>

int main()
{
	char first_name[20], last_name[20];
	printf("성과 이름을 입력하세요: ");
	scanf("%19s %19s", last_name, first_name);
	printf("성: %s 이름: %s\n", last_name, first_name);
}

