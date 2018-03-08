#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
void printList(Element *);

int main(){
	Element *list=NULL;

	int control = 1;
	while(control){
		int a;
		scanf("%d", &a);

		if(a>=0){
			Element *e = malloc(sizeof(Element));
			e->info = a;
			e->next = NULL;
			push(&list,e);
		}

		if(a<0){
			printList(list);
			control = 0;
		}
	}

	return 0;
}

void push(Element **list, Element *e){
	if(*list != NULL){
		e->next = **&list;
	}else{
		e->next = NULL;
	}

	*list = e;
}

void printList(Element *list){
	if(list != NULL){
		printf("%d -> ", list->info);
		
		printList(list->next);
		
	}else{
		printf("NULL");
	}
}