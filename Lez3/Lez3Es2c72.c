#include <stdio.h>

int main(){
	float a;
	scanf("%f", &a);

	printf("%.2f", ((a*1.8f) + 32));

	return 0;
}