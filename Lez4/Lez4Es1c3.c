#include <stdio.h>

int main(){
	int a[10];

	int dim = 10;

	for(int i=0,j=dim-1;i<dim;i++, j--){
		int tmp;
		scanf("%d", &tmp);
		if(tmp%2==0){
			tmp/=2;
		}
		a[j] = tmp;
	}

	for(int i=0;i<dim;i++){
		printf("%d\n", a[i]);
	}
	return 0;
}