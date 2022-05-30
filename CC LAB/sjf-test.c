#include<stdio.h>
#include<stdlib.h>
struct process
{
    int pid,at,bt,ct,wt,tat;
    struct process *next;
}*current;
float awt=0,atat=0;
int time=0;
void insert(int p,int a,int b)
{
    struct process *New=(struct process*)malloc(sizeof(struct process));
    struct process *temp=current;
    New->pid=p;
    New->at=a;
    New->bt=b;
    New->next=NULL;
    if(current==NULL)
    {
        current=New;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=New;
    }
}
int swap()
{
    struct process *temp=current;
    struct process *t,*first;
    int tp,ta,tb,n=0;
    while(temp!=NULL)
    {
        t=temp;
        first=temp;
        while(t!=NULL){
        if((t->at)<(first->at))
        {
            first=t;
        }
        else if((t->at)==(first->at))
        {
            if((t->bt)<(first->bt))
            {
                first=t;
            }
        }
        t=t->next;
        }
        tp=temp->pid;
        ta=temp->at;
        tb=temp->bt;
        temp->pid=first->pid;
        temp->at=first->at;
        temp->bt=first->bt;
        first->pid=tp;
        first->at=ta;
        first->bt=tb;
        temp=temp->next;
    }
    return n;
}
void calculate()
{
        int n=swap();
        struct process *temp;
        printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
        while(current!=NULL)
        {
            if(current->at<=time)
            {
                time+=current->bt;
                current->ct=time;
                current->tat=(current->ct)-(current->at);
                current->wt=(current->tat)-(current->bt);
                awt+=current->wt;
                atat+=current->tat;
                n++;
                printf("%d\t%d\t%d\t%d\t%d\t%d \n",current->pid,current->at,current->bt,current->ct,current->tat,current->wt);
                temp=current;
                current=current->next;
                free(temp);
            }
            else
            {
                time++;
            }
        }
        awt/=n;
        atat/=n;
        printf("Average Waiting Time:%f\nAverage Turnaround Time=%f\n",awt,atat);
}
int main()
{
    int i,p,a,b;
    fflush(stdin);
    printf("Enter the no of processes:");
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        printf("Enter the Arrival Time:");
        fflush(stdin);
        scanf("%d",&a);
        printf("Enter the Burst Time:");
        fflush(stdin);
        scanf("%d",&b);
        insert(i+1,a,b);
    }
    calculate();
    return 0;
}
