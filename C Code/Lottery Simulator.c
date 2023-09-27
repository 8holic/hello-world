#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{int input,in1,in2,in3,money=200;
int win1,win2,win3,win4,pity=0,rng;
printf("Welcome to the ticket scratcher, it only cost 10 dollar to play");

while(money>0)
{
printf("You have %d$\n",money);
printf("What is your two input(1-99):\n");
scanf("%d",&input);
money-=10;
input>100? printf("This input is invalid, ticket has been voided\n"):input<0?printf("This input is invalid, ticket has been voided\n"):printf("You have purchased a valid ticket\n");

/* Generate win number*/
srand(time(NULL));
win1=rand()%99+1;
win2=rand()%99+1;
win3=rand()%99+1;
rng=rand()%10+1;
if(pity>=20&&rng>4&&input>100&&input>0)
    {
        win4=input;
    }
else if(pity<=-20&&rng>9&&input>100&&input>0)
    {
        win4=input+1;
        win1=input-1;
    }
else if(input>100&&input>0)
    {
        win4=rand()%99+1;
    }

input == win1? printf("You won first prize of 1000$!\n"),money+=1000,pity=-45:printf("You didnt win first prize\n"),pity++;
input == win2? printf("You won second prize of 700$!\n"),money+=700,pity=-40:printf("You didnt win second prize\n"),pity++;
input == win3? printf("You won third prize of 300$!\n"),money+=300,pity=-35:printf("You didnt win third prize\n"),pity++;
input == win4? printf("You won the consolation prize of 50$.\n"),money+=50,pity-=30:printf("You didnt win consolation prize\n"),pity++;


printf("\nThe winning numbers are:\nFirst Prize:%d \nSecond Prize:%d\nThird Prize:%d\nConsolation Prize:%d\n\n",win1,win2,win3,win4);
}
printf("You have run out of money to continue playing");

}
