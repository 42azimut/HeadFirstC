#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;
char* ADS[] = {
	"윌리엄: 독신흑인남 유머 감각 스포츠, TV, 외식 좋아함",
	"매트: 독신백인남 비흡연 미술, 영화, 연극 좋아함",
	"루이스: 독신라틴남 비음주 독서, 연극, 미술 좋아함",
	"마이크: 이혼백인남 음주흡연 트럭, 스포츠, 비버 좋아함",
	"피터: 독신아시아남 체스, 운동, 미술 좋아함",
	"조쉬: 독신유태인남 스포츠, 영화, 연극 좋아함",
	"제드: 이혼흑인남 연극, 독서, 외식 좋아함"
};

int sports_no_bieber(char *s)
{
	return strstr(s, "스포츠") && !strstr(s, "비버");
}

int sports_or_workout(char* s)
{
	return strstr(s, "스포츠") || strstr(s, "운동");
}

int ns_theater(char* s)
{
	return strstr(s, "비흡연") && strstr(s, "연극");
}

int arts_theater_or_dining(char* s)
{
	return strstr(s, "미술") || strstr(s, "연극") || strstr(s, "외식");
}

void find(int (*match)(char*))
{
	int i;
	puts("검색 결과:");
	puts("------------------------");
	for (i = 0; i < NUM_ADS; i++) {
		if (match(ADS[i])) { 
			printf("%s\n", ADS[i]);
		}
	}
	puts("------------------------");
}

int main()
{
	find(sports_no_bieber);
	find(sports_or_workout);
	find(ns_theater);
	find(arts_theater_or_dining);

	return 0;
}

