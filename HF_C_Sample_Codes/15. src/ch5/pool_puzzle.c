#include <stdio.h>

struct fish {
	const char* name;
	const char* species;
	int teeth;
	int age;
};

void catalog(struct fish f)
{
	printf("%s는 %s종이며, 이빨이 %i 개고 %i 살입니다.\n",
		f.name, f.species, f.teeth, f.age);
}

void label(struct fish f)
{
	printf("이름: %s\n종: %s\n이빨 수: %i\n나이: %i\n",
		f.name, f.species, f.teeth, f.age);
}

int main()
{
	struct fish snappy = {"Snappy", "Piranha", 69, 4};
	catalog(snappy);
	label(snappy);

	return 0;
}
