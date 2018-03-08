#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
	struct element * prec;
} Element;

void pushOrdered(Element **, Element *);
void insertMissing(Element **,Element **, int);
Element* newElement(int);
void printList(Element *);

int main(){
	Element *list=NULL;

	int control = 1;

	while(control){
		int a;
		scanf("%d", &a);

		if(a>=0){
			pushOrdered(&list,newElement(a));
		}

		if(a<0){
			if(list!=NULL){
				insertMissing(&list,&list->next, list->info-1);
			}
			printList(list);
			control--;
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

void insertMissing(Element **head,Element **list, int n){
	if(*list != NULL){
		Element *tmp = *list;
		if(tmp->info < n){
			Element *e = newElement(n);
			pushOrdered(head,e);
			insertMissing(head,&e->next,n-1);
		}else if(tmp->info == n){
			insertMissing(head,&tmp->next,n-1);
		}else{
			insertMissing(head,&tmp->next,n);
		}
	}
}

void pushOrdered(Element **list, Element *e){
	if(*list != NULL){
		Element *tmp = *list;
		if(e->info >= tmp->info){
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
		printf("%d --> ", list->info);
		printList(list->next);
	}else{
		printf("NULL\n");
	}
}