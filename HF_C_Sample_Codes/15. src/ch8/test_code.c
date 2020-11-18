#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main()
{
	char s[] = "Speak friend and enter";
	encrypt(s);
	printf("함호화된 문장: %s\n", s);
	printf("체크섬: %i\n", checksum(s));
	encrypt(s);
	printf("복호화된 문장: %s\n", s);
	printf("체크섬: %i\n", checksum(s));

	return 0;
}

	
