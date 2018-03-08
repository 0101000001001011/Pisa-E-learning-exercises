#include <stdio.h>

int main(){
	int a[10];
	float sum = 0;
	int count = 0;

	for(int i=0; i<10;i++){
		scanf("%d", &a[i]);
	}

	for(int i=0; i<10;i++){
		if(a[i]!=0 && (a[i]*a[9])>0){
			sum+=a[i];
			count++;
		}
	}	
	printf("%.2f", sum/count);

	return 0;
}
