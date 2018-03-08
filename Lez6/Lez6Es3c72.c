#include <stdio.h>

int main(){
	int min;

	scanf("%d", &min);
	printf("%d\n", min);

	for(int i=0;i<9;i++){
		int tmp;
		scanf("%d", &tmp);

		if(tmp<min)
			min = tmp;

		if(i%2==0)
			printf("0\n");
		else
			printf("%d\n", tmp);
	}
	printf("%d", min);

	return 0;
}