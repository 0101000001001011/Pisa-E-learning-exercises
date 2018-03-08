#include <stdio.h>
#include <stdlib.h>

struct Employee{
	int id;
	int month;
	int year;
	int salary;
};

int main(){
	struct Employee employees[2];
	int perc;

	for(int i=0;i<2;i++){
		scanf("%d", &employees[i].id);
		scanf("%d", &employees[i].month);
		scanf("%d", &employees[i].year);
		scanf("%d", &employees[i].salary);
	}

	scanf("%d", &perc);

	for(int i=0;i<2;i++){
		if(employees[i].year<=2000){
			if(employees[i].year!=2000 || employees[i].month<5){
				employees[i].salary+= employees[i].salary*perc/100;
			}
		}

		if(employees[i].salary>1200){
			printf("%d %d\n", employees[i].id, employees[i].salary);
		}
	}
	
	return 0;
}