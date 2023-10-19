#include <stdio.h>
#include <math.h>

float power(float num,float pow);
float area(float width,float height);
float yValue(float num4,float num3,float num2,float num1,float xValue);

int main(void)
{
float lowerbound,upperbound,pow,num1,num2,num3,num4,xValue,width,result,height;
printf("Please enter the lower and upper bound\n");
 //Determine lower and upper bound//
do
{
printf("lowerbound=");scanf("%f",&lowerbound);
printf("upperbound=");scanf("%f",&upperbound);
    if(lowerbound>upperbound)
    {
        printf("Lowerbound is higher or equal to upper bound! Please enter valid values\n");
    }
}
while(lowerbound>upperbound);

printf("Please enter the polynominal equation: aX^3+bX^2+cX+d\n");
scanf("%f %f %f %f",&num4,&num3,&num2,&num1);
printf("%f %f %f %f\n",num4,num3,num2,num1);
printf("%f",yValue(num4,num3,num2,num1,0));

width=(upperbound-lowerbound)/1000;
printf("%f",width);
for(xValue=lowerbound;xValue<upperbound;xValue+=width)
    {
        height =yValue(num4,num3,num2,num1,xValue);
        result += area(width,height);
        printf("%f,%f,%f\n",xValue,height,result);
    }
printf("Result is %f",result);
}




float power(float num,float pow)
{
    float counter;
    float result=num;
    for(counter=1;counter<pow;counter++)
    {
        result*=num;
    }
    return result;
}

float area(float width,float height)
{
    return width*height;
}

float yValue(float num4,float num3,float num2,float num1,float xValue)
{
     return (num4*power(xValue,3)+num3*power(xValue,2)+num2*power(xValue,1)+num1);
}
