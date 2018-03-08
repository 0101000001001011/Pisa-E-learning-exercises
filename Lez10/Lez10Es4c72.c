#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
void pop(Element **,Element *,int);
void printList(Element *);

int main(){
	Element *list=NULL;

	int control = 1;
	int n;
	scanf("%d", &n);
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
			pop(&list,NULL,n);
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

void pop(Element **list, Element *prec, int a){
	if(*list != NULL){
		Element *e = *list;
		if(e->info%a==0){
			if(prec != NULL){
				prec->next = e->next;
				free(e);
				pop(&prec->next,prec,a);
			}else{
				*list = e->next;
				free(e);
				pop(list,NULL,a);
			}
		}else{
			pop(&e->next,e,a);
		}
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