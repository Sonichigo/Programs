#include <stdio.h>
int main() {
    int data[5];
    int *p;
    printf("Enter elements: ");
    for (int i = 0; i < 5; ++i)
        scanf("%d", data + i);
    p=data;
    printf("Using pointer :-: \n");
    for (int i = 0; i < 5; ++i)
        printf("%d\n", *(data + i));
    printf("Using subscript :-: \n");
    for (int i = 0; i < 5; ++i)
        printf("%d\n", data[i]);
    printf("Using pointer|By address  :-: \n");
    for (int i = 0; i < 5; ++i)
        printf("%d%u\n", *(p+i),&p[i]);
    printf("Using subscript|by address :-: \n");
    for (int i = 0; i < 5; ++i)
        printf("%d %u\n", p[i],&p[i]);

    return 0;
}
