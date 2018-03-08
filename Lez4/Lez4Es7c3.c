#include <stdio.h>

int main(){
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);

	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if((i==0 || i==a-1) || (j==0 || j==b-1)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
