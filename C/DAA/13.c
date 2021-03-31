#include <stdio.h>
#include<time.h>
#include <stdlib.h>
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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
	mergeSort(arr, 0, n - 1);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	printf("%f\n", time_taken);
	}
	return 0;
}