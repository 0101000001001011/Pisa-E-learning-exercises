#include <stdio.h>

void multipli(int,int);

int main(){
	int a,b;

	scanf("%d", &a);
	scanf("%d", &b);

	multipli(a,b);

	return 0;
}

void multipli(int n, int m){
	for(int i=1;i<n;i++){
		if(i%m==0){
			printf("%d\n", i);
		}
	}
}
