#include <stdio.h>

int main(){
	int a, max;

	scanf("%d", &max);
	for(int i=0; i<2; i++){
		scanf("%d", &a);
		if(max < a){
			max = a;
		}
	}

	printf("%d", max);

	return 0;
}