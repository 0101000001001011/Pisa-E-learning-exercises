#include <stdio.h>
#include <stdlib.h>

//List structure:
struct E1 {
	int info;
	struct E1 *next;	
};

typedef struct E1 ElementoLista;
typedef ElementoLista *ListaDiElementi;

// Functions/Procedure to be implemented:

void readList(ListaDiElementi *);
void cancellaDuplicates(ListaDiElementi *);
void filterLists(ListaDiElementi *, ListaDiElementi);


// Function to print all the elements of the list:
void printList(ListaDiElementi list){
	printf("(");
	while(list!=NULL){
		printf("%d ", list->info);
		list = list->next;
	}
	printf(")\n");
}

int main(){
	ListaDiElementi firstlist,secondlist;

	// Read and print the first list:
	
	readList(&firstlist);
	readList(&secondlist);

	printf("Prima lista\n");
	printList(firstlist);
	
	// Eliminates Duplicates from the first list:

	cancellaDuplicates(&firstlist);
	
	printf("Prima lista senza duplicati\n");
	printList(firstlist);

	// Read and print the secondlist:
	
	printf("Seconda lista\n");
	printList(secondlist);

	// Eliminates Duplicates from the secondlist:

	cancellaDuplicates(&secondlist);
	
	printf("Seconda lista senza duplicati\n");
	printList(secondlist);
	
	// Filter the first list using the elements of the secondlist:
	
	filterLists(&firstlist, secondlist);

	// Print the filtered list:

	printf("Lista filtrata\n");
	printList(firstlist);
	
	return 0;
}

void filterLists(ListaDiElementi *list, ListaDiElementi filter){
	int empty = 0;
	if(*list != NULL){
		while(filter != NULL){
			ListaDiElementi actual = *list;
			ListaDiElementi precedent = NULL;
			ListaDiElementi after = (*list)->next;

			while(after != NULL){
				if(actual->info == filter->info){
					if(precedent!=NULL){
						actual = after;
						free(precedent->next);
						precedent->next = after;
						after = after->next;
						precedent = precedent->next;
					}else{
						*list = after;
						free(actual);
						actual = *list;
					}
				}else{
					if(precedent!=NULL){
						precedent = precedent->next;
					}else{ precedent = *list; }
					actual = actual->next;
					after = after->next;
				}
			}

			if(actual!=NULL){
				if(actual->info == filter->info){
					if(precedent!=NULL){
						free(precedent->next);
						precedent->next=NULL;
					}else{
						*list = actual;
						free(*list);
						empty = 1;
					}
				}
			}

			filter = filter->next;
		}
	}
	if(empty){
		*list = NULL;
	}
}

void cancellaDuplicates(ListaDiElementi *list){
	if(*list != NULL){
		ListaDiElementi actual = *list;
		while(actual->next!=NULL){
			ListaDiElementi after = actual->next->next;
			if(actual->info == actual->next->info){
				free(actual->next);
				actual->next=after;
			}else if(actual->next!=NULL){
				actual = actual->next;
			}
		}
	}
}

void readList(ListaDiElementi *list){
	int control = 1, first = 1;
	int precedent, num;

	*list = NULL;

	while(control){
		scanf("%d", &num);

		if(num >= precedent || first){

			ListaDiElementi e = malloc(sizeof(ElementoLista));
			e->info = num;
			e->next;

			if(*list != NULL){
				ListaDiElementi tmp = *list;
				while(tmp->next!=NULL){
					tmp = tmp->next;
				}
				tmp->next = e;
			}else{
				*list = e; 
			}
		}else{
			control--;
		}

		precedent = num;
		if(first){ first--; }
	}
}