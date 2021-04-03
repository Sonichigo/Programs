#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (int arr[], int L, int F) 
{ 
	int p = arr[F]; 
	int i = (L - 1);  
	int j;
	for (j = L; j <= F- 1; j++) 
	{ 
 
		if (arr[j] < p) 
		{ 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[F]); 
	return (i + 1); 
} 

void QuickSort(int arr[], int l, int f) 
{ 
	if (l < f) 
	{ 
		
		int p = partition(arr, l, f);  
		QuickSort(arr,l, p - 1); 
		QuickSort(arr,p + 1,f); 
	} 
} 
int main(void) {
    int n,i,x;
    clock_t start1,end1;
	double time1;
	int arr[100000];
	int nn[]={20000,25000,30000,35000,40000,45000,50000,55000,60000,65000,70000,75000}; 
   for(x=0;x<11;x++)
	{
	    n=nn[x];
	for(i=0;i<n;i++)
		arr[i]=rand()%n;
	start1=clock();
	QuickSort(arr,0,n-1);
	end1=clock();
	time1=((double)(end1-start1))/CLOCKS_PER_SEC;
	printf("%f\n",time1);
    }
	return 0;
}