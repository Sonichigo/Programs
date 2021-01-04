#include<stdio.h>
int main()
{
    int a[3][4]={{10,11,12,13},{20,21,22,23},{30,31,32,33}};
    int (*p)[4];
    p=a;
    int i,j;
    printf("Elements in the 2D array are\n");
    for(i=0;i<3;i++)
    for(j=0;j<4;j++)
    {
        printf("%d ",a[i][j]);
        if(j==3)
        printf("\n");
    }
    printf("\n");
    printf("Elements in the 2D array are using pointer\n");
     for(i=0;i<3;i++)
    for(j=0;j<4;j++)
    {
        printf("%d ",p[i][j]);
        if(j==3)
        printf("\n");
    }
     printf(" Address of the Elements in the 2D array\n");
     for(i=0;i<3;i++)
    for(j=0;j<4;j++)
    {
        printf("%d ",&a[i][j]);
        if(j==3)
        printf("\n");
    }
     printf("Elements in the 2D array are using pointer\n");
     for(i=0;i<3;i++)
    for(j=0;j<4;j++)
    {
        printf("%d ",*(*(p+i)+j));
        if(j==3)
        printf("\n");
    }
    printf(" Address of the Elements in the 2D array using array\n");
     for(i=0;i<3;i++)
    for(j=0;j<4;j++)
    {
        printf("%d ",(*(p+i)+j));
        if(j==3)
        printf("\n");
    }
    return 0;
}