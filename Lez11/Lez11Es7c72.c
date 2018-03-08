#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
	struct element * prec;
} Element;

void pushOrdered(Element **, Element *);
Element* newElement(int);
int printList(Element *);
void fusionLists(Element **,Element **,Element **);

int main(){
	Element *list1=NULL,*list2=NULL,*list3=NULL;

	int control = 2;

	while(control){
		int a;
		scanf("%d", &a);

		if(a>=0){
			if(control%2){
				pushOrdered(&list2,newElement(a));
			}else{
				pushOrdered(&list1,newElement(a));
			}
		}

		if(a<0){
			control--;
		}
	}

	fusionLists(&list3,&list1,&list2);
	printList(list3);

	return 0;
}

void fusionLists(Element **list,Element **a,Element **b){
	Element *tmp = *a;
	
	if(tmp!=NULL){
		pushOrdered(list,newElement(tmp->info));
		fusionLists(list,&tmp->next,b);
		free(tmp);
	}else{
		tmp = *b;
		if(tmp!=NULL){
			pushOrdered(list,newElement(tmp->info));
			fusionLists(list,a,&tmp->next);
			free(tmp);
		}
	}
}

Element* newElement(int a){
	Element *e = malloc(sizeof(Element));
	e->info = a;
	e->next = NULL;
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

int printList(Element *list){
	if(list != NULL){
		printf("%d --> ", list->info);
		printList(list->next);
	}else{
		printf("NULL\n");
	}
}