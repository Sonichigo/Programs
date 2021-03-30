#include<stdio.h>
#include<time.h>
#include<stdlib.h>
double t;
int linear(int[],int,int);
int main()
{
	int i,ar[50000],item,n,index;
	printf("Enter size:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ar[i]=rand()%n;
	}
	printf("Last element:%d",ar[n-1]);
	printf("\nEnter element to be searched for:");
	scanf("%d",&item);
	t = clock();
	index=linear(ar,n,item);
	if(index==1)
	printf("\nNumber not present\n");
	else
	printf("\nElement found at index:%d",index);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nTime taken:%f\n", time_taken);
	return 0;
}
int linear(int ar[],int size,int item)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(ar[i]==item)
		return i;
	}
	return -1;
}