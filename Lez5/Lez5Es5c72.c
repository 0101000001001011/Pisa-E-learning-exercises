#include <stdio.h>

int main(){
	int a;

	scanf("%d", &a);

	float pi=0;
	for(int i=0,j=1;i<a;i++,j+=2){
		if(i%2==0)
			pi+=(float)4/j;
		else
			pi-=(float)4/j;
	}

	printf("%.6f", pi);

	return 0;
}
