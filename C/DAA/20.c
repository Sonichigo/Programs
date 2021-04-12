#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
    for (k = i; k < j; k++) 
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }
    return min;
}
int main()
{
    int i, x;
    printf("Enter the array size: ");
    scanf("%d ",&x);
    int arr[x];
    for(i=0;i<x;i++)
    {
        arr[i]=(int *)malloc(x *sizeof(int));
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ",
        MatrixChainOrder(arr, 1, n - 1));
    getchar();
    return 0;
}