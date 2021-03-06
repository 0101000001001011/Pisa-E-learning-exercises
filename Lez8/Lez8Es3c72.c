#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
	struct element * prec;
} Element;

Element* newElement(int);

void pushOrdered(Element **, Element *);

void printList(Element *);

int main(){
	Element *list=NULL;

	int control = 1;
	while(control){
		int a;
		scanf("%d", &a);

		if(a>0){
			pushOrdered(&list,newElement(a));
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
	e->prec = NULL;
	return e;
}

void pushOrdered(Element **list, Element *e){
	if(*list != NULL){
		Element *tmp = *list;
		if(e->info <= tmp->info){
			if(tmp->prec != NULL){
				tmp->prec->next = e;
				e->prec = tmp->prec;
			}else{
				*list = e; 
			}
			
			e->next = tmp;
			tmp->prec = e;
		}else{
			pushOrdered(&(tmp->next),e);
		}
	}else{
		*list = e; 
	}
}

void printList(Element *list){
	if(list != NULL){
		printf("%d\n", list->info);
		if(list->next != NULL){
			printList(list->next);
		}
	}
}