#include <stdio.h>

int main(){
	int a;

	scanf("%d", &a);
	
	printf("%d", (((a%2)-1)*-1));

	return 0;
}