#include<stdlib.h>
#include <iostream> 
using namespace std; 
struct Node { 
	int data; 
	Node* prev; 
	Node* next; 
}; 
void insertAtTheBegin(struct Node **start_ref, int data) 
{ 
	struct Node *ptr1 = new Node; 
	ptr1->data = data; 
	ptr1->next = *start_ref; 
	if (*start_ref != NULL) 
	(*start_ref)->prev = ptr1; 
	*start_ref = ptr1; 
} 
void deleteNode(struct Node** head_ref, struct Node* del) 
{ 

    if (*head_ref == NULL || del == NULL) 
        return; 
  
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    free(del); 
    return; 
} 
void printList(struct Node *start) 
{ 
	struct Node *temp = start; 
	cout << endl; 
	while (temp!=NULL) 
	{ 
		cout << temp->data << " "; 
		temp = temp->next; 
	} 
} 
void bubbleSort(struct Node *start) 
{ 
	int swapped, i; 
	struct Node *ptr1; 
	struct Node *lptr = NULL; 

	
	if (start == NULL) 
		return; 

	do
	{ 
		swapped = 0; 
		ptr1 = start; 

		while (ptr1->next != lptr) 
		{ 
			if (ptr1->data > ptr1->next->data) 
			{ 
				swap(ptr1->data, ptr1->next->data); 
				swapped = 1; 
			} 
			ptr1 = ptr1->next; 
		} 
		lptr = ptr1; 
	} 
	while (swapped); 
} 
int main() 
{ 
	int arr[] = {12, 56, 2, 11, 1, 90}; 
	int list_size, i; 

	struct Node *start = NULL; 
	for (i = 0; i< 6; i++) 
		insertAtTheBegin(&start, arr[i]); 
	printf("\n Linked list before sorting "); 
	printList(start); 
	bubbleSort(start); 
	printf("\n Linked list after sorting "); 
	printList(start); 
	deleteNode(&start,start);
	deleteNode(&start,start->next);
	printf("\n After deletion:\n");
	printList(start);
	return 0; 
} 