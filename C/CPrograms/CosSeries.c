#include<stdio.h>
#include<math.h>

void main()
{
	int n,i,x1,j;
	float x,sign,cosx,fact;
	printf("Enter the numbers\n");
	scanf("%d %f",&n,&x);
	x1=x;
	x=x*(3.14159/180);
	cosx=1;
	sign=1;
	for(i=2;i<=n;i++)
	{	
		fact=1;
		for(j=1;j<=i;j++)
		{
			fact=fact*j;
		}	
		cosx=cosx+(pow(x,i)/fact*sign);
		sign=sign*(-1);
	}
	printf("The sum series of cosine is : %.4f\n",cosx);
	printf("The value of cos(%d)using : %f\n",x1,cos(x));
}
