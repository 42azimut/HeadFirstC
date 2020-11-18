#include <string.h>
#include <stdio.h>

char tracks[][80] = {
    "George Soros bought 18,457,516 shares of PLTR",
    "The attention he brings to PLTR has investing implications",
    "There are several political surprises behind this investment",
    "I'm going to first cover the basics in this article",
    "Before I get too far ahead of myself, just a quick couple of extra notes"
};

void find_track(char search_for[]){
    int i;
    while (i < 5){
        if(strstr(tracks[i], search_for))
            printf("노래 %i: '%s'\n", i, tracks[i]);
        i++;
    }
}

int main(){
    char search_for[80];
    scanf("%79s", search_for);
    printf("검색할 내용: ");
    find_track(search_for);
    return 0;
}
