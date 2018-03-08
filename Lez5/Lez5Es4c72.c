#include <stdio.h>

int MCD(unsigned int,unsigned int);
int mcm(int,int);

int main(){
	unsigned int b;
	unsigned int a;

	scanf("%u", &a);
	scanf("%u", &b);

	printf("%d\n", MCD(a,b));

	printf("%d", mcm(a,b));

	return 0;
}

int MCD(unsigned int n, unsigned int m){
	if(m==0)
		return n;
	if(n>m)
		return MCD(m,n%m);
	else
		return MCD(n,m%n);
}

int mcm(int n, int m){
	return (n*m)/MCD(n,m);
}
