#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int info;
	struct element * next;
} Element;

void push(Element **, Element *);
Element* newElement(int);
int printList(Element *, int);
void printCount(Element *list, int, int);

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
			printCount(list,printList(list,0),0);
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

int printList(Element *list, int sum){
	if(list != NULL){
		return printList(list->next,sum+list->info);
	}else{
		printf("%d\n", sum);
		return sum;
	}
}

void printCount(Element *list, int sum, int count){
	if(list != NULL){
		if((float)list->info > (float)(sum/4))
			count++;

		printCount(list->next,sum,count);
	}else{
		printf("%d\n", count);
	}
}