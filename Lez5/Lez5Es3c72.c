#include <stdio.h>

float sum_pow(float,int);

int main(){
	float b;
	int a;

	scanf("%d", &a);
	scanf("%f", &b);

	printf("%.2f", sum_pow(b,a));

	return 0;
}

float sum_pow(float n, int m){
	float sum=1;
	for(int i=1;i<=m;i++){
		float a=n;
		for(int j=0;j<i-1;j++){
			a*=n;
		}
		sum+=a;
	}
	return sum;
}
