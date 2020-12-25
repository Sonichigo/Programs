#include <stdio.h> 
  
void Swap(int* a, int* b) 
{ 
    int temp = *b; 
    *b = *a; 
    *a = temp; 
} 
  
int main() 
{ 
    int a , b, c;
    scanf("%d %d %d",&a,&b,&c);
    printf("Value before swapping:\n"); 
    printf("a = %d \nb = %d \nc = %d\n", a, b, c); 
  
    Swap(&a,&b); 
    Swap(&c,&a);
  
    printf("Value after swapping:\n"); 
    printf("a = %d \nb = %d \nc = %d", a, b, c); 
  
    return 0; 
}