#include <stdio.h>
#include <stdlib.h>

typedef struct human{
	char name[11];
	struct human * mother;
	struct human * father;
} Human;

int main(){
	Human family[3];

	char names[30];
	scanf("%s", names);

	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			family[i].name[j] = names[i*10+j];
		}
		family[i].name[10] = '\0';

		family[i].mother = NULL;
		family[i].father = NULL; 
	}

	family[0].mother = &family[1];
	family[0].father = &family[2];

	for(int i=0;i<3;i++){
		printf("%s\n", family[i].name);
		if(family[i].mother != NULL){
			printf("%s", family[i].mother->name);
		}else{
			printf("Sconosciuto");
		}
		if(family[i].father != NULL){
			printf("%s", family[i].father->name);
		}else{
			printf("Sconosciuto");
		}
		printf("\n");
	}

	
	return 0;
}