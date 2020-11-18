#include <stdio.h>

void where_is_quote(char quote[])
{
	printf("quote 문자열은 %p 번지에 저장되어 있습니다.\n", quote);
}

int main()
{
	where_is_quote("Cookies make you fat");

	return 0;
}

