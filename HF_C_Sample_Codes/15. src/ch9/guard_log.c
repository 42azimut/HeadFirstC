#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

/* 주 제어판 프로그램.
   경비원의 점검 시각을 기록한다. */

int main()
{
	char comment[80];
	char cmd[120];

	fgets(comment, 80, stdin);
	sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

	system(cmd);
	return 0;
}

