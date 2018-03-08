#include <stdio.h>

int fatt(int);

int main(){
	int f;
	scanf("%d", &f);

	printf("%d", fatt(f));

	return 0;
}

int fatt(int f){
	if(f == 0)
		return 1;
	if(f == 1)
		return 1;
	
	return f*fatt(f-1);
}