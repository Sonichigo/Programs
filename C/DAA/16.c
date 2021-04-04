#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void random_shuffle(int arr[],int n)
{
    srand(time(NULL));
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int arr[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1);
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
void quick_sort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partion(arr, p, q);
        quick_sort(arr, p, j-1);
        quick_sort(arr, j+1, q);
    }
}
int main()
{
    int n,i;
    clock_t start1,end1,start2,end2;
	double time1,time2;
    printf("Enter array size - \n");
	scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; i++)
        arr[i] = i;
    start1=clock();
    random_shuffle(arr,n);
    quick_sort(arr, 0, n-1);
    end1=clock()-start1;
	time1=((double)(end1))/CLOCKS_PER_SEC;
    start2=clock();
    quick_sort(arr, 0, n-1);
    end2=clock()-start2;
	time2=((double)(end2))/CLOCKS_PER_SEC;
	printf("RANDOM %f NORMAL %f",time1,time2);
    return 0;
}