#include<stdio.h>
#include<stdlib.h>
struct Node 
{ 
	int data; 
	struct Node *next; 
};
struct Node *addToEmpty(struct Node *last, int data) 
{ 
	if (last != NULL) 
	return last; 
	struct Node *temp = 
		(struct Node*)malloc(sizeof(struct Node)); 
	temp -> data = data; 
	last = temp; 
	last -> next = last; 
	return last; 
} 
struct Node *addBegin(struct Node *last, int data) 
{ 
	if (last == NULL) 
		return addToEmpty(last, data); 
	struct Node *temp = 
			(struct Node *)malloc(sizeof(struct Node)); 
	temp -> data = data; 
	temp -> next = last -> next; 
	last -> next = temp; 
	return last; 
} 
struct Node *addEnd(struct Node *last, int data) 
{ 
	if (last == NULL) 
		return addToEmpty(last, data); 
	
	struct Node *temp = 
		(struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = last -> next; 
	last -> next = temp; 
	last = temp; 

	return last; 
} 

struct Node *addAfter(struct Node *last, int data, int item) 
{ 
	if (last == NULL) 
		return NULL; 

	struct Node *temp, *p; 
	p = last -> next; 
	do
	{ 
		if (p ->data == item) 
		{ 
			temp = (struct Node *)malloc(sizeof(struct Node)); 
			temp -> data = data; 
			temp -> next = p -> next; 
			p -> next = temp; 
			if (p == last) 
				last = temp; 
			return last; 
		} 
		p = p -> next; 
	} while(p != last -> next); 
	printf("%d not present in the list.\n",item); 
	return last; 
} 
void traverse(struct Node *last) 
{ 
	struct Node *p; 
	if (last == NULL) 
	{ 
		printf("List is empty.\n"); 
		return; 
	} 
	p = last -> next; 
	do
	{ 
		printf("%d ",p -> data); 
		p = p -> next; 
	} 
	while(p != last->next); 
} 
void deleteNode(struct Node** head, int key)  
{ 
    if (*head == NULL) 
        return; 
    if((*head)->data==key && (*head)->next==*head) 
    { 
        free(*head); 
        *head=NULL; 
        return; 
    } 
    struct Node *last=*head,*d; 
    if((*head)->data==key) { 
          
            while(last->next!=*head) 
            last=last->next; 
 
        last->next=(*head)->next; 
        free(*head); 
        *head=last->next; 
    }   
    while(last->next!=*head&&last->next->data!=key) 
	{ 
        last=last->next; 
    }
    if(last->next->data==key) { 
        d=last->next; 
        last->next=d->next; 
        free(d); 
    } 
    else
        printf("Not Present\n");
    } 
struct Node *exchangeNodes(struct Node *head)
{
    struct Node *p = head;
    while (p->next->next != head)
       p = p->next;
    p->next->next = head->next;
    head->next = p->next;
    p->next = head;
    head = head->next;
    return head;
}
int main() 
{ 
	struct Node *last = NULL; 
	int ch;
	do{
	printf("\n SELECT THE OPTION \n");
	printf("\n 1.Insert \n 2.Deletion \n 3.Swapping \n 4.Exit\n");
	scanf("%d",&ch);
	switch (ch)
	{
	case 1:
			last = addToEmpty(last, 6); 
			last = addBegin(last, 4); 
			last = addBegin(last, 2); 
			last = addEnd(last, 8); 
			last = addEnd(last, 12); 
			printf("Linked List:\n");
			traverse(last); 
		break;
	case 2:
			deleteNode(&last,4);
			printf("\nAfter deletion:\n");
			traverse(last);
		break;
	case 3:
			printf("\nAfter swaping:\n");
			last = exchangeNodes(last);
			traverse(last);
		break;
	default:
		break;
	}
	}
	while(ch<4);
	return 0; 
}