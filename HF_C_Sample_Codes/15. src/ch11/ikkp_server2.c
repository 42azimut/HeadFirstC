#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

void error(char* msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int open_listener_socket()
{
	int s = socket(PF_INET, SOCK_STREAM, 0);
	if (s == -1)
		error("소켓을 열 수 없습니다.");

	return s;
}

void bind_to_port(int socket, int port)
{
	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	int reuse = 1;
	if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int)) == -1)
		error("소켓에 재사용 옵션을 설정할 수 없습니다.");
	int c = bind(socket, (struct sockaddr*)&name, sizeof(name));
	if (c == -1)
		error("소켓에 바인딩할 수 없습니다.");
}

int catch_signal(int sig, void (*handler)(int))
{
        struct sigaction action;
        action.sa_handler = handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;
        return sigaction(sig, &action, NULL);
}

int say(int socket, char* s)
{
	int result = send(socket, s, strlen(s), 0);
	if (result == -1)
		fprintf(stderr, "%s: %s\n", "클라이언트에 메시지를 보낼 수 없습니다.", strerror(errno));
	return result;
}

int listener_d;

void handle_shutdown(int sig)
{
	if (listener_d)
		close(listener_d);

	fprintf(stderr, "안녕!\n");
	exit(0);
}

int read_in(int socket, char* buf, int len)
{
	char* s = buf;
	int slen = len;
	int c = recv(socket, s, slen, 0);
	while ( (c > 0) && (s[c-1] != '\n')) {
		s += c; slen -= c;
		c = recv(socket, s, slen, 0);
	}
	if ( c < 0 )
		return c;
	else if (c == 0)
		buf[0] = '\0';
	else
		s[c-1] = '\0';
	return len - slen;
}

int main(int argc, char* argv[])
{
	if (catch_signal(SIGINT, handle_shutdown) == -1)
		error("인터럽트 처리기를 설정할 수 없습니다.");

	listener_d = open_listener_socket();
	bind_to_port(listener_d, 30000);
	if (listen(listener_d, 10) == -1)
		error("들을 수 없습니다.");

	struct sockaddr_storage client_addr;
	unsigned int address_size = sizeof(client_addr);
	puts("연결을 기다립니다.");
	char buf[255];
	while(1) {
		int connect_d = accept(listener_d, (struct sockaddr*)&client_addr, &address_size);
		if (connect_d == -1)
			error("두 번째 소켓을 열 수 없습니다.");
		if ( !fork() ) {
			close(listener_d);
			if (say(connect_d, "인터넷 노크노크 프로토콜 서버\r\n버전 1.0\r\nKnock Knock!\r\n") != -1) {
				read_in(connect_d, buf, sizeof(buf));
				if (strncasecmp("Who's there?", buf, 12))
					say(connect_d, "'Who's there?'라고 질문했어야 합니다!");
				else {
					if (say(connect_d, "Oscar\r\n") != -1) {
						read_in(connect_d, buf,sizeof(buf));
						if (strncasecmp("Oscar who?", buf, 10))
							say(connect_d, "'Oscar who?'라고 질문했어야 합니다!");
						else
							say(connect_d, "Oscar silly question, you get a silly answer.\r\n");
					}
				}
			}
			close(connect_d);
			exit(0);
		}
		close(connect_d);
	}
	return 0;
}
