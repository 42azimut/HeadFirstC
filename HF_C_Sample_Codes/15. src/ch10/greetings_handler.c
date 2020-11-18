#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void diediedie(int sig)
{
	puts("잔인한 세상이여, 안녕...\n");
	exit(1);
}

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction(sig, &action, NULL);
}

int main()
{
	if (catch_signal(SIGINT, diediedie) == -1) {
		fprintf(stderr, "처리기를 매핑할 수 없습니다.");
		exit(2);
	}
	char name[30];
	printf("이름을 입력하세요: ");
	fgets(name, 30, stdin);
	printf("안녕 %s\n", name);
	return 0;
}

