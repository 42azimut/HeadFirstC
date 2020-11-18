#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("INT_MAX 값은 %i입니다.\n", INT_MAX);
	printf("INT_MIN 값은 %i입니다.\n", INT_MIN);
	printf("int형은 %li바이트를 차지합니다.\n", sizeof(int));

	printf("FLT_MAX 값은 %f입니다.\n", FLT_MAX);
	printf("FLT_MIN 값은 %.50f입니다.\n", FLT_MIN);
	printf("float형은 %li바이트를 차지합니다.\n", sizeof(float));

	return 0;
}

