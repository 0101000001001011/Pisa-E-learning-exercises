#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
Element* newElement(int);
void pop(Element **,int);
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
			scanf("%d", &a);
			pop(&list,a);
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
		Element *next = *list;
		push(&next->next,e);
	}else{
		e->next = NULL;
		*list = e;
	}
}

void pop(Element **list, int n){
	if(*list != NULL && n){
		Element *e = *list;
		*list = e->next;
		free(e);
		pop(list,n-1);
	}
}

void printList(Element *list){
	if(list != NULL){
		printf("%d -> ", list->info);
		printList(list->next);
	}else{
		printf("NULL");	
	}
}