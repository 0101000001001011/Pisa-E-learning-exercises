#include <stdio.h>

int fibbo(int);

int main(){
	int a;
	scanf("%d", &a);

	int i=0, fib=0;
	while(fib<=a){
		fib = fibbo(i);
		if(fib<=a)
			printf("%d\n", fib);
		i++;
	}

	return 0;
}

int fibbo(int f){
	if(f == 0){
		return 0;
	}

	if(f == 1){
		return 1;
	}

	int fi = fibbo(f-2) + fibbo(f-1) ;
	return fi;
}