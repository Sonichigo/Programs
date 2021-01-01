* To impliment stack using array */
#include<stdio.h>
#include<stdlib.h>
int num[100],choice,top,c;
void push();
void pop();
void display();

void main()
{
                  c=1;
                  top=-1;
                  while(c==1)
                  {
                                    printf("Enter 1 to enter in the stack\n");
                                    printf("Enter 2 to delete from stack\n");
                                    printf("Enter 3 to display from stack\n");
                                    printf("Enter 4 to exit from stack\n");
                                    scanf("%d",&choice);
                                    switch(choice)
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
                                        }
                                        printf("Enter 1 to continue and 0 to exit\n");
                                        scanf("%d",&c);
                      }
 }
 void push()
 {
                  int x;
                 
                                    top+=1;
                                    printf("Enter the number to be inserted\n");
                                    scanf("%d",&x);
                                    num[top]=x;
                          
  }
  void pop()
  {
                  if(top<=-1)
                  {
                                    printf("Stack Underflow");
                                    exit(1);
                    }
                    else
                    {
                                  
                                    int y=num[top];
                                    top --;
                                    printf("\nValue Deleted =%d",y);
                      }
 }
 void display()
 {
                  if(top>=0)
                  {
                                    printf("The Numbers present in the stack are\n");
                                    for(int i=top;i>=0;i--)
                                    {
                                                      printf("%d\n",num[i]);
                                      }
                     }
                     else
                     {
                                    printf("Stack is Empty");
                       }
 }
