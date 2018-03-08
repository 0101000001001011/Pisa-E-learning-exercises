#include <stdio.h>

int main(){
	float a;
	float sum = 0;

	for(int i=0; i<3; i++){
		scanf("%f", &a);
		sum += a;
	}

	printf("%.3f", (sum/3));

	return 0;
}