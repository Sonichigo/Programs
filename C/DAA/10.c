#include<stdio.h>
int main()
{
	int i, key, j; 
	int k;
	long int c1,c2,c3;
	
	int arr[90],nn,n;
	nn=20;
	int an[]={4,5,6,7,8,9,12,17,19,20,25,26,27,28,29,34,35,36,45,46,50};
	for(k=0;k<nn;k++)
	{
	c1=c2=c3=0;	
	n=an[k];
	printf("\nsize: %d",n);
	
	
	for(i=0;i<n;i++)
		arr[i]=i+1;

    for (i = 1; i < n; i++) 
	{
		c1++; 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
            c1++; 
        } 
        arr[j + 1] = key; 
    }
		
	for(i=0;i<n;i++)
		arr[i]=n-i+1;
		
	for (i = 1; i < n; i++) 
	{ 
		c2++;
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
			c2++;
        } 
        arr[j + 1] = key; 
    } 
	
	for(i=0;i<n;i++)
		arr[i]=rand()%n;
	for (i = 1; i < n; i++) 
	{ 
		c3++;
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
			c3++;
        } 
        arr[j + 1] = key; 
    } 
    printf("\n");
    for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nasc.c1: %d\nhap.c3: %d\ndsc.c2: %d",c1,c3,c2);
}
    return 0;
}
