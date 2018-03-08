#include <stdio.h>

int main(){
	int a;

	scanf("%d", &a);

	int count =0;
	for(int i=0;i<5;i++){
		int b;
		scanf("%d", &b);
		if(b>a)
			count++;
	}

	printf("%d", count);
	return 0;
}
