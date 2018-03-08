#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
void pushAfter4(Element **, Element *, int);
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
			scanf("%d", &a);
			pushAfter4(&list,newElement(a),3);
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

void pushAfter4(Element **list, Element *e,int n){
	Element *actu = *list;
	if(*list != NULL){
		if(actu->next != NULL && n){
			pushAfter4(&actu->next,e,n-1);
		}else{
			e->next = actu->next;
			actu->next = e;
		}
	}else{
		e->next = NULL;
		*list = e;
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