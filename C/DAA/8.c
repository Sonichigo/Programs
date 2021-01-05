#include<stdio.h>
#include<stdlib.h>
int count1=0,count2=0;
void prime1(int n)
{
	int i,flag=0;
	for(i=2;i<n;i++)
	{
		count1++;
		if(n%i==0)			
		flag++;
	}
	if(flag>0)
	    printf("\nNot a prime");
	else
	    printf("\nPrime Number");
printf(" %d\n",count1);
}
void prime2(int n)
{
	int i,flag=0;
	for(i=2;i<n/2;i++)
	{
		count2++;
		if(n%i==0)
		flag++;
	}
	if(flag>0)
	    printf("\nNot a prime");
	else
	    printf("\nPrime Number");
printf(" %d\n",count2); 
}
int main()
{
	int n,i;
    printf("ENTER THE NUMBERS TO CHECK ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the %d elements ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        prime1(a[i]);
        prime2(a[i]);
    }
	return 0;
}