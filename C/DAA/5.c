#include<stdio.h>
int main()
{
	int n , i , j ,ar[50][50],sum=0,c=0,prod=1;
	printf("Enter number of rows and columns\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d\n",&ar[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",ar[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(ar[i][j]!=0)
			{
				c++;
			}
        }
    }
    printf("NUMBER OF NON ZERO ELEMENTS:%d\n",c);
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<j)
			sum+=ar[i][j];
		}
	}
	printf("SUM OF ELEMENTS ABOVE DIAGONAL:%d\n",sum);
	
	printf("ELEMENTS BELOW MINOR DIAGONAL: ");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i+j==(n+1))
			printf("%d",ar[i][j]);
		}
	}
    printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				prod*=ar[i][j];
			}
		}
	}
	printf("PRODUCT OF ELEMENTS OF DIAGONAL:%d\n",prod);
	return 0;
}