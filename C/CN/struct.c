#include <stdio.h>
struct student_info{
int roll_no;
char name[50];
float CGPA;
int age;
};


void display(struct student_info s);

int main() {
   struct student_info s1;
   
   printf("Enter rollNo: ");
   scanf("%d", &s1.roll_no);

   printf("Enter name: ");
   scanf("%c", &s1.name);

   printf("Enter CGPA: ");
   scanf("%f", &s1.CGPA);

   printf("Enter age: ");
   scanf("%d", &s1.age);

   display(s1);

   return 0;
}

void display(struct student_info s) {
   printf("\nDisplaying information\n");
   printf("Name: %s", s.name);
   printf("\nAge: %d", s.age);
}