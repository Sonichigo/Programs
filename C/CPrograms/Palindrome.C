#include<stdio.h>

void main()
{
	int n,r=0,re,x;
	printf("Enter the number\n");
	scanf("%d",&n);
	x=n;	
	while(n!=0)
	{
		re=n%10;
		r=r*10+re;
		n/=10;	
	}
	if(x==r)
	{
	printf("Palindrome");
	}
	else
	{
	printf("Not Plaindrome");	
	}
}
