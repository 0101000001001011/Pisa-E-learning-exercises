#include <stdio.h>

int main(){
	int a[5], b[5];

	printf("[");
	for(int i=0; i<5;i++){
		scanf("%d", &a[i]);
		printf("%d", a[i]);
		if(i!=4)
			printf(",");
	}
	printf("]\n");

	printf("[");
	for(int i=0; i<5;i++){
		scanf("%d", &b[i]);
		printf("%d", b[i]);
		if(i!=4)
			printf(",");
	}
	printf("]\n");
	
	printf("[");
	for(int i=0; i<5;i++){
		printf("%d", a[i]+b[i]);
		if(i!=4)
			printf(",");
	}
	printf("]");	

	return 0;
}
