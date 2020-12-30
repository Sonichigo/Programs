#include<stdio.h>

void main()
{
	int n,x,i,j,c=1;
	printf("Enter the Number\n");
	scanf("%d",&n);
	c=n-1;
	x=n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			printf(" ");
		}
		c++;
		for(j=1;j<=2*(n-i)+1;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
