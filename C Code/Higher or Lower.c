#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int card();

int main(void)
{
    int cardnow,cardfuture,guess,result;
    float trackearn=0,tracklost=0,money=100,bet=1;
    printf("Welcome to higher or lower!\n");
    srand(time(NULL));
    printf("You start with 100$, guess if the next card is higher or lower\n");
    while(money>0&&bet>0)
    {
        bet=0;
        result=0;
        printf("Please enter how much you want to bet:\n");
        scanf("%f",&bet);
        if(bet>0&&bet<=money)
        {
            cardnow=card();
            money-=bet;
            printf("1 - higher || 2 - lower\n");
            do
            {
                printf("Please enter a valid value:\n");
                scanf("%d",&guess);
            }
            while(guess!=1&&guess!=2);
            cardfuture=card();
            if(cardfuture>cardnow && guess==1)
            {
                printf("You successfully guessed that the next card is higher\n");
                money+=bet*1.5;
                trackearn+=bet*1.5;
            }
            else if(cardfuture<cardnow && guess==2)
            {
                printf("You successfully guessed that the next card is lower\n");
                money+=bet*1.5;
                trackearn+=bet*1.5;
            }
            else
            {
                printf("You did not guess correctly\n");
                tracklost-=bet;
            }
        }
        else if(bet>money)
        {
            printf("You cannot bet more than what you have!\n");
        }
        else
        {
            printf("You left the betting table\n");
        }
        printf("You now have %.2f\n",money);
        }

    printf("Earnings:%.2f Losses:%.2f",trackearn,tracklost);
}


int cardrigged()
{
    int card=rand()%11+2;
    switch(card)
    {
        case 14:printf("This should not be printed!\n");break;
        case 13:printf("The dealer drew a King\n");break;
        case 12:printf("The dealer drew a Queen\n");break;
        case 11:printf("The dealer drew a Jack\n");break;
        default:printf("The dealer drew %d\n",card);break;
    }
    return card;
}


int card()
{
    int card=rand()%14+1;
    switch(card)
    {
        case 14:printf("The dealer drew an Ace\n");break;
        case 13:printf("The dealer drew a King\n");break;
        case 12:printf("The dealer drew a Queen\n");break;
        case 11:printf("The dealer drew a Jack\n");break;
        default:printf("The dealer drew %d\n",card);break;
    }
    return card;
}


