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
	Element *list1=NULL, *list2=NULL, *list3=NULL;

	int control = 1;
	while(control){
		int a;
		scanf("%d", &a);

		if(a>0){
			pushOrdered(&list1,newElement(a));
		}

		if(a<0){
			control = 0;
		}
	}

	control = 1;
	while(control){
		int a;
		scanf("%d", &a);

		if(a>0){
			pushOrdered(&list2,newElement(a));
		}

		if(a<0){
			control = 0;
		}
	}

	while(list1!=NULL){
		Element *listTmp = list2;

		int control1 = 1;
		if(list1->next != NULL){
			if(list1->info == list1->next->info){
				control1 = 0;
			}
		}
		
		if(control1){
			int control2 = 1;
			while(listTmp!=NULL && control2){
				if(list1->info == listTmp->info){
					int control3 = 1;
					if(listTmp->next != NULL){
						if(list1->info == listTmp->next->info){
							control3 = 0;
						}
					}

					if(control3){
						pushOrdered(&list3, newElement(list1->info));
					}
				}
				
				if(list1->info < listTmp->info){
					control2 = 0;
				}
				listTmp = listTmp->next;
			}
		}

		list1 = list1->next;
	}

	printList(list3);

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