#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
Element* newElement(int);
void printList(Element *,int);

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
			printList(list,1);
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
	if(list != NULL){
		e->next = *list;
	}else{
		e->next = NULL;
	}
	*list = e;
}

void printList(Element *list, int first){
	if(list != NULL){
		printList(list->next,0);
		printf("%d -> ", list->info);
	}

	if(first){
		printf("NULL\n");
	}
}