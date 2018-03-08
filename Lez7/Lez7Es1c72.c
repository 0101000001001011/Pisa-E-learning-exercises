#include <stdio.h>
#include <stdlib.h>

struct Cat{
	int id;
	int age;
	float weight;
	int food;
};

int main(){
	const char* foods[] = {"crocchette","scatolette","tonno"};
	struct Cat cats[4];

	float weightMed=0;
	for(int i=0;i<4;i++){
		scanf("%d", &cats[i].id);
		scanf("%d", &cats[i].age);
		scanf("%f", &cats[i].weight);
		scanf("%d", &cats[i].food);

		weightMed += cats[i].weight;
	}
	weightMed /= 4;

	for(int i=0;i<4;i++){
		if(cats[i].age < 4 && cats[i].weight>weightMed){
			printf("%d %s\n", cats[i].id, foods[cats[i].food]);
		}
	}

	return 0;
}