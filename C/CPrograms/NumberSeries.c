#include<stdio.h>
#include<math.h>

void main()
{
	int n,c=0,i;
	printf("Enter the number\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	
		c=c+pow(i,2);
	}
	printf("The Sum is %d\n",c);
}
