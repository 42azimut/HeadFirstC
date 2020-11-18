#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
	char* name;
	char* opens;
	char* closes;
	struct island* next;
} island;

void display(island *start)
{
	island* i = start;

	for (; i != NULL; i = i ->next) {
		printf("섬 이름: %s\n운행 시간: %s - %s\n", i->name, i->opens, i->closes);
	}
}

island* create(char* name)
{
	island* i = malloc(sizeof(island));
	i->name = strdup((const char*)name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;

	return i;
}

int main()
{
	char name[80];
	fgets(name, 80, stdin);
	island* p_island0 = create(name);
	fgets(name, 80, stdin);
	island* p_island1 = create(name);
	p_island0->next = p_island1;

	display(p_island0);

	return 0;
}

