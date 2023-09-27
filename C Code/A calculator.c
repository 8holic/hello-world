#include <stdio.h>

int main(void)
{
    char sign;
    float num1,num2,result;
    int valid=1;
    printf("Please enter your operator: ");
    scanf("%f %c %f",&num1,&sign,&num2);
    switch(sign)
    {
        case '+':result=num1+num2;break;
        case '-':result=num1-num2;break;
        case '*':result=num1*num2;break;
        case '/':result=num1/num2;break;
        default:
            printf("Operator is invalid!");
            valid=0;
            break;

    }
    if(valid==1)
    {
        printf("%.5f %c %.5f = %.5f",num1,sign,num2,result);
    }
}

