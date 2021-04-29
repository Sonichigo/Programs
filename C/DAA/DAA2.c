#include<math.h> 
#include<stdio.h> 
#include<time.h>
void insertSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 
 int main()
{

	double t;
	int arr[100000];
	int i,x,n;
	int nn[]={20000,25000,30000,35000,40000,45000,50000,55000,60000,65000};
	for(x=0;x<10;x++)
	{
	
	n=nn[x];
	for(i=0;i<n;i++)
		arr[i]=rand()%n;
	
	t = clock();
	insertSort(arr,n);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	printf("%f\n", time_taken);
	}
	return 0;
}