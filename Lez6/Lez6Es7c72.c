#include <stdio.h>
#include <stdlib.h>

void asd(int**,int**);

int main(){
	int **a = malloc(4*sizeof(int*));
	int **b = malloc(4*sizeof(int*));

	for(int i=0;i<4;i++){
		a[i] = malloc(4*sizeof(int));
		for(int j=0;j<3;j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(int i=0;i<4;i++){
		b[i] = malloc(4*sizeof(int));
		for(int j=0;j<3;j++){
			scanf("%d", &b[i][j]);
		}
	}

	asd(a,b);

	return 0;
}

void asd(int **a,int **b){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(j!=2)
				printf("%d ", a[i][j]+b[i][j]);
			else
				printf("%d", a[i][j]+b[i][j]);
		}
		printf("\n");
	}
}