#include <stdio.h>

int main()
{
	int nums[] = { 1, 2, 3};
	printf("nums의 주소는 %p 입니다.\n", nums);
	printf("nums + 1의 주소는 %p 입니다.\n", nums + 1);

	return 0;
}

