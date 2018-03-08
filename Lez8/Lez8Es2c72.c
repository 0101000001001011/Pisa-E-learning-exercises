#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
	struct element * prec;
} Element;

Element* newElement(int);

void pushFront(Element **, Element *);
void pushBack(Element **, Element *);

Element* pop(Element **, int);

void printList(Element *);

int main(){
	Element *list=NULL;

	int control = 1;
	while(control){
		int a;
		scanf("%d", &a);

		if(a>0 && a%2==0){
			pushFront(&list,newElement(a));
		}

		if(a>0 && a%2!=0){
			pushBack(&list,newElement(a));
		}

		if(a<0){
			Element *removed = pop(&list, a*-1);
			free(removed);
			removed = NULL;
		}

		if(a==0){
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

void pushFront(Element **list, Element *e){
	if(*list != NULL){
		Element *tmp = *list;
		e->next = **&list;
		tmp->prec = e;
	}else{
		e->next = NULL;
	}

	e->prec = NULL;
	*list = e;
}

void pushBack(Element **list, Element *e){
	if(*list != NULL){
		Element *tmp = *list;
		if(tmp->next == NULL){
			tmp->next = e;
			e->next = NULL;
			e->prec = tmp;
		}else{
			pushBack(&(tmp->next), e);
		}
	}else{
		pushFront(list,e);
	}
}

Element* pop(Element **list, int a){
	if(*list != NULL){
		Element *e = *list;
		if(e->info == a){
			if(e->prec != NULL){
				e->prec->next = e->next;
			}else{
				*list = e->next; 
			}

			if(e->next != NULL){
				e->next->prec = e->prec;
			}

			return e;
		}else{
			return pop(&(e->next),a);
		}
	}else{
		return *list;
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