#include<stdio.h>
#include<stdlib.h>
int main()
{
      int *a,n,i,j,t;
      printf("Enter n: ");
      scanf("%d",&n);
      a=(int *)malloc(n *sizeof(int));
      for(i=0;i<=n-1;i++)
      {
            *(a+i)=rand()%n;
      }
      for(i=0;i<n;i++)
      {
            for(j=0;j<=i;j++)
            {
                  if(*(a+i)<*(a+j))
                  {
                        t=*(a+i);
                        *(a+i)=*(a+j);
                        *(a+j)=t;
                  }
            }
      }
      printf("Largest:%d\n",*(a+n-1));
      printf("Smallest:%d",*(a));
      return 0;
}
