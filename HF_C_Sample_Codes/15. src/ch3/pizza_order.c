#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char* delivery = "";
	int thick = 0;
	int count = 0;
	char ch;

	while ((ch = getopt(argc, argv, "d:t")) != EOF)
		switch (ch) {
		case 'd':
			delivery = optarg;
			break;
		case 't':
			thick = 1;
			break;
		default:
			fprintf(stderr, "알 수 없는 옵션: '%s'\n", optarg);
			return 1;
		}

	argc -= optind;
	argv += optind;

	if (thick)
		puts("두꺼운 크러스트.");

	if (delivery[0])
		printf("%s 배달할 피자.\n", delivery);

	puts("재료: ");

	for (count = 0; count < argc; count++)
		puts(argv[count]);

	return 0;
}
