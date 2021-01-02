#include<stdio.h>
#include<stdlib.h>
struct Node 
{ 
  int data; 
  struct Node *next; 
}; 

//PUSH OR ADD BEFORE

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

//ADD AFTER

void insertAfter(struct Node* prev_node, int new_data)  
{  
    
    if (prev_node == NULL)  
    {  
    printf("the given previous node cannot be NULL");      
    return;  
    }  
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));  
    new_node->data = new_data;  
    new_node->next = prev_node->next;  
    prev_node->next = new_node;  
}

//ADD AT LAST

void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  	struct Node *last = *head_ref;  
    new_node->data  = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
} 

//PRINT 

void printList(struct Node *node) 
{ 
	struct Node *d=node;
  while (d != NULL) 
  { 
     printf(" %d ", d->data); 
     d = d->next; 
  } 
} 

//DELETE NODE when value is given

void deleteNode(struct Node **head_ref, int key) 
{ 
    struct Node* temp = *head_ref, *prev; 
  
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   
        free(temp);               
        return; 
    }  
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
	prev->next = temp->next; 
    free(temp);  
} 

//DELETE when position is given

void deleteNodepos(struct Node **head_ref, int position) 
{ 

   if (*head_ref == NULL) 
      return; 
   struct Node* temp = *head_ref; 
  
    if (position == 0) 
    { 
        *head_ref = temp->next;  
        free(temp);              
        return; 
    } 
    int i=0;
  	while(temp!=NULL && i<position-1)
	{
	  
         temp = temp->next;
		 i++; 
	}
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct Node *next = temp->next->next; 
  	free(temp->next);  
    temp->next = next; 
} 

//REVERSE

static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 

// SORT THE LINKED LIST
void bubbleSort(struct Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
    /* Checking for empty list */
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
                	int temp = ptr1->data; 
    				ptr1->data = ptr1->next->data; 
    				ptr1->next->data= temp;  
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  
//COUNT THE NO OF TIMES A NUMBER IS PRESENT

int count(struct Node* head, int search_for) 
{ 
    struct Node* current = head; 
    int count = 0; 
    while (current != NULL) { 
        if (current->data == search_for) 
            count++; 
        current = current->next; 
    } 
    return count; 
} 
  
// DELETE A LINKED LIST

void deleteList(struct Node** head_ref) 
{ 
   struct Node* current = *head_ref; 
   struct Node* next; 
  
   while (current != NULL)  
   { 
       next = current->next; 
       free(current); 
       current = next; 
   } 
   *head_ref = NULL; 
} 

int main()
{
	struct Node* head = NULL; 
	push(&head, 7);
	push(&head,8);
	insertAfter(head->next,5);
	insertAfter(head->next,6);
	push(&head,9);
	append(&head,4);
	int pos;
	deleteNode(&head,8);
	printf("Enter the position from which element is to be deleted:");
	scanf("%d",&pos);
	int n;
	printf("\nEnter the number to be searched:");
	scanf("%d",&n);
	count(head,n);
	deleteNodepos(&head,pos);
	printList(head);
	reverse(&head);
	printf("\nAfter Reversing:\n");
	printList(head);
	deleteList(&head);
}
