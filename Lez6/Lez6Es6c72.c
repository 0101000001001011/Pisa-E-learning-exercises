#include <stdio.h>
#include <stdlib.h>

int asd(int**);

int main(){
	int **a = malloc(4*sizeof(int*));

	for(int i=0;i<4;i++){
		a[i] = malloc(4*sizeof(int));
		for(int j=0;j<3;j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("%d", asd(a));

	return 0;
}

int asd(int **a){
	int index = -1;

	for(int i=0;i<3;i++){
		int control = 1;

		for(int j=0;j<4 && control;j++){
			if(a[j][i]%3!=0)
				control = 0;
		}

		if(control)
			index = i;
	}
	return index;
}