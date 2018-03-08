#include <stdio.h>

void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc);

int main(){
	int dim=7;
	int arr[dim];
	int primaocc=-1,ultimaocc=-1;

	for(int i=0;i<dim;i++){
		scanf("%d", &arr[i]);
	}

	primoultimopari(arr,dim,&primaocc,&ultimaocc);
	printf("%d %d", primaocc,ultimaocc);
	return 0;
}

void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc){
	for(int i=0;i<dim;i++){
		if(arr[i]%2==0){
			if(*primaocc == -1)
				*primaocc = i;

			*ultimaocc = i;
		}
	}
}