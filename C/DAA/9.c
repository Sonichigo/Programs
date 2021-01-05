#include <stdio.h>
void ecluid()
{
    int m, n;
    printf("\nEnter-two integer numbers: ");
    scanf ("%d %d", &m, &n);
    while (n > 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    printf ("GCD = %d \n",m);
}
void middleschool()
{
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d %d",&n1,&n2);

    while(n1!=n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    printf("GCD = %d",n1);
}
int main() {
    middleschool();
    ecluid();
    return 0;
}