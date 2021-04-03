#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{

	double t;
	int arr[100000];
	int i,x,n;
	int nn[]={20000,25000,30000,35000,40000,45000,50000,55000,60000,                   
         65000};
	for(x=0;x<10;x++)
	{
	
	n=nn[x];
	for(i=0;i<n;i++)
		arr[i]=rand()%n;
	
	t = clock();
	heapSort(arr, n);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	printf("%f\n", time_taken);
	}
	return 0;
}