#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
Element* newElement(int);
int printList(Element *, int, int);

int main(){
	Element *list=NULL;

	int control = 1;
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	
	while(control){
		int a;
		scanf("%d", &a);

		if(a>=0){
			push(&list,newElement(a));
		}

		if(a<0){
			printf("%d" ,printList(list,n,m));
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

int printList(Element *list, int n, int m){
	if(list != NULL){
		int num;
		if(list->info > n && list->info < m){
			num = list->info;
		}else{ num = 1; }

		if(list->next != NULL){
			return num*printList(list->next,n,m);
		}else{
			return num;
		}
	}else{
		return -1;
	}
}