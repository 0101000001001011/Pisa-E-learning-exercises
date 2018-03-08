#include <stdio.h>

void ordered_swap(int*,int*,int*); 
void swap(int*,int*); 

int main(){
	int a,b,c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	ordered_swap(&a,&b,&c);

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d", c);
	return 0;
}

void ordered_swap(int* a,int* b,int* c){
	swap(a,b);
	swap(a,c);
	swap(b,c);
}

void swap(int* a,int* b){
	if(*a>*b){
		int tmp = *b;
		*b=*a;
		*a=tmp;
	}
}