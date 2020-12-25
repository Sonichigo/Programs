#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr;
    int i, j, n, count = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    arr=(int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        *(arr+i)=rand()%(n/2);
    }
	int num=0,rep=0,check=0;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(*(arr+i) == *(arr+j))
            {
				rep++;
                count++;
                break;
            }
            
        }
        if(rep>check)
            {
            	check=rep;
            	num=*(arr+i);
			}
		rep=0;
    }
	printf("Total number of duplicate elements found in array = %d",count);
	printf("\nMaximum repeating element:%d",num);
	return 0;
}