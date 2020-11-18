#include <stdio.h>

enum response_type { DUMP, SECOND_CHANCE, MARRIAGE };
typedef struct {
	char* name;
	enum response_type type;
} response;

void dump(response r)
{
	printf("%s께.\n", r.name);
	puts("안타깝게도 귀하가 지난 번에 만난 데이트 상대자께서");
	puts("귀하를 다시 만나고 싶지 않다고 합니다.");
}

void second_chance(response r)
{
	printf("%s께.\n", r.name);
	puts("좋은 소식입니다. 귀하가 지난 번에 만난 데이트 상대께서");
	puts("귀하를 다시 만나고 싶어 합니다. 바로 전화주세요.");
}

void marriage(response r)
{
	printf("%s께.\n", r.name);
	puts("축하드립니다! 귀하가 지난 번에 만난 데이트 상대께서");
	puts("결혼하고 싶다고 알려왔습니다.");
}

int main()
{
	response r[] = {
		{"마이크", DUMP}, {"루이스", SECOND_CHANCE},
		{"매트", SECOND_CHANCE}, {"윌리엄", MARRIAGE}
	};
	int i;
	for (i=0; i<4; i++) {
		switch( r[i].type) {
		case DUMP:
			dump(r[i]);
			break;
		case SECOND_CHANCE:
			second_chance(r[i]);
			break;
		default:
			marriage(r[i]);
		}
	}
	return 0;
}




