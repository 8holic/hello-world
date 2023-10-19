#include <stdio.h>
#include <math.h>

float definiteintegrate(float num,float power,float XValue);
float power(float num,float power);

int main(void)
{
    float num1=1,power,lowerlim,higherlim,result=0;
    int breakloop=0;
    printf("Please enter the lower and upper limit with a space: ");
    scanf("%f%f",&lowerlim,&higherlim);

    while(num1!=0)
    {
        printf("Please enter the value of a and b you want to integrate in this format: aX^b\nFinish integrating by entering:0 0\n");
        scanf("%f%f",&num1,&power);
        result+=definiteintegrate(num1,power,higherlim)-definiteintegrate(num1,power,lowerlim);
    }
    printf("Integration result is :%f",result);

}

float power(float num,float power)
{
    float counter;
    float result=num;
    for(counter=1;counter<power;counter++)
    {
        result*=num;
    }
    return result;
}

float definiteintegrate(float num,float pow,float XValue)
{
    float intpower=pow+1,result;
    if(intpower==0)
    {
        result=num*log(abs(XValue));
    }
    else
    {
        result=(num/intpower)*power(XValue,intpower);
    }
    return result;
}
