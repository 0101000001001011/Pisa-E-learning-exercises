#include <stdio.h>

void asd(int a[], int b[]);

int main(){
	int a[3],b[3];

	for(int i=0;i<3;i++){
		scanf("%d", &a[i]);
	}

	for(int i=0;i<3;i++){
		scanf("%d", &b[i]);
	}

	asd(a,b);

	return 0;
}

void asd(int a[], int b[]){
	unsigned int tmp = 0;
	for(int i=0;i<3 && !tmp;i++){
		tmp = 1;
		for(int j=0;j<3 && tmp;j++){
			if(a[i]>=b[j]){
				tmp = 0;
			}
		}

		if(tmp)
			printf("TRUE");
	}
	if(!tmp)
		printf("FALSE");
}