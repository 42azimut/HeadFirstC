#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	char* advice[] = {
		"조금만 드세요.\r\n",
		"꽉 끼는 청바지를 입으세요. 뚱뚱해 보이지는 않을 겁니다.\r\n",
		"한 마디만 하겠습니다. 옳지 않아요.\r\n",
		"오늘만이라도 솔직해지세요. 직장 상사에게 '진정' 생각하고 있는 걸 말하세요.\r\n",
		"그 머리 모양은 아니지 싶습니다.\r\n"
	};
	int listener_d = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(listener_d, (struct sockaddr*)&name, sizeof(name));
	listen(listener_d, 10);
	puts("연결을 기다립니다.");
	while (1) {
		struct sockaddr_storage client_addr;
		unsigned int address_size = sizeof(client_addr);
		int connect_d = accept(listener_d, (struct sockaddr*)&client_addr, &address_size);
		char* msg = advice[rand() % 5];
		send(connect_d, msg, strlen(msg), 0);
		close(connect_d);
	}
	return 0;
}

