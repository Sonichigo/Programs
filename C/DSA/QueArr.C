/* Creating a queue using array*/
#include<stdio.h>
#include<stdlib.h>
int rear=-1,front =-1;
int num[100];
void push()
{
            int n;
            if(front==-1 || rear==-1)
            {
                     front =rear=0;
            }
            printf("\nEnter the Number to be inserted:");
            scanf("%d",&n);
            num[rear]=n;
            rear++;
  }
  void pop()
  {
                  if(front==-1)
                  {
                                    printf("underflow");
                    }
                    else if(front == rear)
                    {
                                    front =-1;
                                    rear =-1;
                     }
                     else
                     {
                                    front++;
                        }
   }
   void display()
   {
                  if(rear==-1 && front ==-1)
                  {
                                    printf("Queue is Empty");
                     }
                     else
                     {
                                    printf("\nThe Queue is:\n");
                                    for(int i=front;i<rear;i++)
                                    {
                                                      printf("%d\n",num[i]);
                                     }
                     }
      }
      void main()
      {
                  int choice=1,c;
                  while(choice==1)
                  {
                                    printf("Enter 1 if u want to insert an element in queue:\n");
                                    printf("Enter 2 if u want to delete an element in queue:\n");
                                    printf("Enter 3 if u want to display the elements present in the queue:\n");
                                    printf("Enter 4 if u want to exit from the queue:\n");
                                    scanf("%d",&c);
                                    switch(c)
                                    {
                                                      case 1:
                                                      push();
                                                      break;
                                                      case 2:
                                                      pop();
                                                      break;
                                                      case 3:
                                                      display();
                                                      break;
                                                      case 4:
                                                      exit(1);
                                                      break;
                                          }
                                          printf("Enter 1 if u want to continue else enter 0\n");
                                          scanf("%d",&choice);
                       }
        }  
