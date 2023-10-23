#include <stdio.h>

int count(int num);
int printfactor(int num);

int main(void)
{
    int num;
    printf("Please enter a whole number:");
    scanf("%d",&num);
    printf("There are %d factors in the number %d\n",count(num),num);
    printf("The factors are:\n");
    printfactor(num);

}

int count(int num)
{
    int counter=0;
    for(int i=1;i<=(num/2);i++)
    {
        if(num%i==0&&i<num/i)
        {
            counter++;
        }
    }
    return counter;
}
int printfactor(int num)
{
    int counter=0;
    for(int i=1;i<=(num/2);i++)
    {
        if(num%i==0&&i<num/i)
        {
            printf("(%d,%d)\n",i,num/i);
        }
    }
    return counter;
}
