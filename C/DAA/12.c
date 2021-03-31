#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LinearSearch(int *arr,int n,int x)
{
    int c=0;
    for(int i=0;i<n;i++)
	{
	    c++;
	    if(arr[i]==x)
	    {
	        return c;
	    }
	}
	return 0;
}
int BinarySearch(int *arr,int n,int num)
{
    int beg=0,end=n-1,c=0;
	int mid=n/2;
	while(beg<=end)
	{
	    c++;
	    mid=(beg+end)/2;
	    if(num<arr[mid])
	    {
	        end=mid-1;
	    }
	    if(num>arr[mid])
	    {
	        beg=mid+1;
	    }
	    if(num==arr[mid])
	    {
	        return c;
	        break;
	    }
	}
	return 0;
}
int main(void) {
	int n;
	clock_t start1,end1,start2,end2;
	double time1,time2;	
	printf("Enter size of array - \n");
	scanf("%d",&n);
	int arr[n],i;
	for(i=0;i<n;i++)
	   arr[i]=i;
	printf("Enter element to be searched for - \n");
	int num;
	scanf("%d",&num);
	start1=clock();
	int l=LinearSearch(arr,n,num);
	printf("%d", l-10);
	end1=clock()-start1;
	time1=((double)(end1))/CLOCKS_PER_SEC;
	start2=clock();
	int r=BinarySearch(arr,n,num);
	printf("%d", r-10);
	end2=clock()-start2;
	time2=((double)(end2))/CLOCKS_PER_SEC;
	printf("Linear Time = %f\tBinary Time = %f",time1,time2);
	return 0;
}