#include <stdio.h>

int change(int num);
int changereference(int *num);

int main()
{
   //pass by value//
   int num=10,result;
   int *point = &num;

    printf("In this code, we are passing the value of num into the function\n");
    printf("Our functions add 5 to the existing value\n");
    printf("Before function call:%d\n",num);
    change(num);
    printf("After function call:%d\n",num);
    printf("As we see here, num is not changed\n\n");

    printf("In this part, we will be doing pass by reference instead\n");
    printf("Before function call:%d\n",num);
    changereference(&num);
    printf("After function call:%d\n",num);
    printf("As we see here, the number is changed\n");
    printf("This is because this function references &num instead\n");
    printf("Instead of printing the value of num for the function,they take the address instead\n");
    printf("*p pointer  ||  & take reference to || *p deference\n\n");

    printf("int *point = &num|| Now p is a pointer pointing to n\n");
    printf("Address %p Value %d\n",num,num);
    *point=20;
    printf("if we assign *point=20 \n");
    printf("Address %p Value %d\n",num,num);
    changereference(point);
    printf("if we call function on point \n");
    printf("Address %p Value %d\n",num,num);
    printf("It is the same as calling &num\n");
}

int change(int num)
{
    num+=5;
    return num;
}
int changereference(int *num)
{
    *num+=5;
    return *num;
}
