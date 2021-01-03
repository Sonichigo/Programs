#include<stdio.h>

void main()
{
	int n,i,x1,j,sum=0;
	float x,sign,p,fact;
	printf("Enter the numbers\n");
	scanf("%d %f",&n,&x);
	x1=x;
	sign=-1;
	for(i=2;i<=n;i++)
	{	
		p=1;
		fact=1;
		for(j=1;j<=i;j++)
		{
				p=p*x;
				fact=fact*j;
		}	
		sign=sign*(-1);
		sum+=p/fact;
	}
	printf("The sum series of sin is : %.4f\n",sum);
}
