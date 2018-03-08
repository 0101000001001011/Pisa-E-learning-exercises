#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
Element* newElement(int);
int findPariODisp(Element *, int);

int main(){
	Element *list=NULL;

	int control = 1;
	while(control){
		int a;
		scanf("%d", &a);

		if(a>=0){
			push(&list,newElement(a));
		}

		if(a<0){
			printf("%d\n", findPariODisp(list,0));
			
			printf("%d\n", findPariODisp(list,1));

			control = 0;
		}
	}

	return 0;
}

Element* newElement(int a){
	Element *e = malloc(sizeof(Element));
	e->info = a;
	e->next = NULL;
	return e;
}

void push(Element **list, Element *e){
	if(*list != NULL){
		Element *next = *list;
		push(&next->next,e);
	}else{
		e->next = NULL;
		*list = e;
	}
}

int findPariODisp(Element *list, int switchPD){
	if(list != NULL){
		if((switchPD && list->info%2==0) || !(switchPD || list->info%2==0)){
			return list->info;
		}else{
			return findPariODisp(list->next,switchPD);
		}
	}else{
		return -1;
	}
}



