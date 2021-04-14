#include <stdio.h>
#include <stdlib.h>
void rearrange_alternate_positions(int arr[], int lb, int ub)
{
int i,j;
int n = ub-lb;
j = 0;
for(i = 0; i < n; i++)
{
if(arr[i] < 0)
{
if(i != j)
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
j++;
}
}
}
int main()
{
int n,i,lb,ub;
printf("\nEnter the upper bound of elements : ");
scanf("%d",&ub);
printf("\nEnter the lower bound of elements : ");
scanf("%d",&lb);
n=ub-lb;
int arr[n];
printf("\nInput the array elements : ");
for(i = 0; i < n; i++)
{
scanf("%d",&arr[i]);
}
printf("\nOriginal array : ");
for(i = 0; i < n; i++)
{
printf("%d ",arr[i]);
}
printf("\n");
rearrange_alternate_positions(arr, lb,ub);
printf("\nRearranged array : ");
for(i = 0; i < n; i++)
{
printf("%d ",arr[i]);
}
printf("\n");
return 0;
}
