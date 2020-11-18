#include <stdio.h>
#include <unistd.h>

int main()
{
	char* my_env[] = {"JUICE=복숭아와 사과", NULL};
	execle("diner_info", "diner_info", "4", NULL, my_env);

	return 0;
}
