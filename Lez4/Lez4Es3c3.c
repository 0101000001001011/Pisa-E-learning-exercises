#include <stdio.h>

int ind(int[], int);

int main(){
	int a[10];
	for(int i=0;i<10;i++){
		scanf("%d", &a[i]);
	}

	printf("%d", ind(a,10));

	return 0;
}

int ind(int a[], int length){
	for(int i=1;i<length-1;i++){
		if(a[i]==a[i+1]-a[i-1])
			return i;
	}
	return -1;
}