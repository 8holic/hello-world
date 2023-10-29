#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
//Set up//
char name[20];
int minIceCream,maxIceCream,bossrespond=0,participants,actualicecream,max,min,input,counter=1,confident=0,proximity,finalvalue,ending;
srand((unsigned) time(NULL));

//Start//
printf("Hello, what is your name?\n");
scanf("%s",name);
printf("Hello %s, we need to buy an assortment of ice cream\n",name);
participants=(rand()%500)+1000;
actualicecream=(rand()%10)*participants;
printf("We have %d participants\n",participants);
max = actualicecream + rand()%rand();
min = actualicecream - rand()%1000;
proximity=actualicecream/100;
printf("As previously agreed we will get between %d and %d ice cream, how much should we get? If you are confident say 0.\n",min,max);

do
    {
    printf("We should get this amount of ice cream:");
    scanf("%d",&input);
            fflush(stdin);
    if(input==0)
    {printf("Looks like you have made up your mind\n");
    break;
    }
    else if(input < min || input>max)
    {
    printf("That is not in the range of what we have agreed upon previously\n");
    counter++;
    }
    else//responses to the amount suggested//
    {
     if(abs(actualicecream-input)<proximity)
     {
        printf("That is near the ideal value! It is within %d of the ideal range\n",proximity);
     }
     else if(abs(actualicecream-input)<(proximity*2))
     {
        printf("That is somewhat ok but it is not within ideal range\n");
     }
     else if(abs(actualicecream-input)<(proximity*4))
     {
        printf("I think we can do a little better\n");
     }
     else if((input-actualicecream)<0)
     {
        bossrespond=rand()%2+1;
        switch(bossrespond)
        {
            case 1:printf("That is definitely insufficient, the people will starve\n");break;
            case 2:printf("That is way too low, the event will fail for sure\n");break;
            default:printf("Unless you plan to make the participants made I suggest you significantly increase the value\n");break;
        }
     }
     else if((actualicecream-input)<0)
     {
        bossrespond=rand()%2+1;
        switch(bossrespond)
        {
            case 1:printf("That is way too much, we will exceed budget\n");break;
            case 2:printf("There is no way the participants can finish that amount of ice creams\n");break;
            default:printf("The excess amount is coming out of your pocket, we are not paying for that\n");break;
        }
     }

    }
    counter++;
    }
while(counter<=5 || input==0);
        fflush(stdin);
printf("The ice cream man is here\nSo how much should we order?\n");
scanf("%d",&finalvalue);
fflush(stdin);
//endings//
    {
     if(abs(actualicecream-finalvalue)<proximity*0.5)
     {
        ending=0;
     }
     else if(abs(actualicecream-finalvalue)<(proximity*1))
     {
        ending=1;
     }
     else if(abs(actualicecream-finalvalue)<(proximity*2))
     {
        ending=2;
     }
     else if(abs(actualicecream-finalvalue)<(proximity*4))
     {
        ending=3;
     }
     else if((finalvalue-actualicecream)<0)
     {
        ending=4;
     }
     else if((actualicecream-finalvalue)<0)
     {
        ending=5;
     }
    }
printf("In the end you bought %d ice cream\n",finalvalue);
printf("The ideal value is %d\n",actualicecream);
switch(ending)
{
    case 0:printf("You bought the perfect amount of ice cream, your boss is awestruck by your foresight.\nYou are expecting a promotion after this");break;
    case 1:printf("You bought near perfect amount of ice cream, your boss is amaze by your choices.\nYou are expecting a pay rise after this");break;
    case 2:printf("You bought an decent amount of ice cream, your boss is pleased with how it turn out.\nYou are in your boss good graces after this");break;
    case 3:printf("You did not really estimate properly ice cream, your boss is annoyed at the fallout.\nYou  will have an performance improvement plan after this");break;
    case 4:printf("You bought so little ice cream that all your participant as well as your boss15 starved to death.\nYou are now being charged for mass murder");break;
    case 5:printf("You bought so much ice cream that you cause an economic collapse.\nThe mob lynched and burned you on a stake");break;
}

}
