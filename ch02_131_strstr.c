#include <stdio.h>
#include <string.h>

int main(){

    char str1[] = "dysfunctional";
    char str2[] = "fun";

    if (strstr(str1, str2))
        puts("같구나!");
    printf("strstr : %p\n", strstr(str1, str2));

    printf("str1 : %p, %.3s, str2 : %p\n", str1+3, str1+3, str2);

    printf("&str : %p, not_str : %p, *str : %s \n", &str2, str2, str2);
    return 0;
}
