#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
Element* newElement(int);
void printList(Element *);

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
			printList(list);
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
		e->next = **&list;
	}else{
		e->next = NULL;
	}
	*list = e;

	if(e->info%2==0){
		push(list,newElement(-1));
	}
}

void printList(Element *list){
	if(list != NULL){
		printf("%d -> ", list->info);
		
		printList(list->next);
		
	}else{
		printf("NULL\n");
	}
}