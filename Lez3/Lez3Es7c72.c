#include <stdio.h>

int main(){
	int a;

	scanf("%d", &a);

	printf("%d h %d min %d s", a/3600, (a-((a/3600)*3600))/60, (a-((a/3600)*3600)-(((a-(a/3600)*3600)/60)*60)));

	return 0;
}