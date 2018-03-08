#include <stdio.h>
#include <stdlib.h>

int pow2(int);

int main(){
	int n;
	scanf("%d",&n);

	printf("%d", pow2(n));
	
	return 0;
}

int pow2(int n){
	if(n == 1)
		return 2;

	if(n>=2)
		return 2*pow2(n-1);

	return 0;
}