#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main(void)
 {
 int dealer,you,money=200,bet,profit,card1,card2,anothercard,cardvalue,dealercard1,decision,betaddition,dealeranother,dealertotal,winning=0,losses=0,cardcounter,dealerblackjack;
 int eventtrigger1=0,eventrigger2=0,eventtrigger3=0,eventrigger4=0,randomeventrigger=0,pregameaction=99,canraise=0,rng;
 int winmultipler=2,dealercheating=100,maxcardvalue=21; /*Adjustable variable to make the game harder or easier*/
 srand(time(NULL));

 printf("Welcome to the Singapore Casino!\n");
 printf("The rules of blackjack are simple:\n");
printf("You will be dealt two cards, the dealer will have one card faced up\n");
printf("You are allowed to draw more cards, but your total card value need to be within 16 and 21\n");
printf("Raising your bet is only allowed before you draw any cards\n");
printf("If you manage to draw 9 without bursting, you win!\n");
printf("We are a very fair casino, you will have equal chance of drawing all cards\n");
 start:
 while(money>0&&money<2500)
 {
     if(winning>1000&&eventtrigger1==0)
     {
         printf("You are doing quite well here, the dealer seems pleased\n");
         dealercheating=98;
         eventtrigger1=1;
     }
     else if(money<150)
     {
         printf("The dealer looks at you with pity\n");
         dealercheating=100;
     }
     else if(money>1500)
     {
         printf("You are winning by quite a bit, the dealer looks fustrated\n");
         dealercheating=90;
     }
     else if(winning>1500&&eventrigger2==0&&randomeventrigger>=6)
     {
         printf("A crowd has gathered to watch, the dealer is restrained in his actions\n");
         dealercheating=100;
         eventrigger2=1;
     }
     else if(eventrigger2==1&&randomeventrigger>=6)
     {
         printf("The crowd has dispersed, the dealer smirks\n");
         dealercheating=90;
         eventrigger2=0;
     }
     else
     {
         printf("\nThe dealer gets ready for the next game\n");
     }


    /*game reset*/
    cardvalue=0;
    dealertotal=0;
    cardcounter=2;
    decision=1;
    maxcardvalue=21;
    winmultipler=3;
    pregameaction=0;
    canraise=0;
    rng=rand()%10+1;
    /*Random Events*/
    randomeventrigger=rand()%10+1;
    if(randomeventrigger==11&&dealercheating<=90)
    {
     printf("The dealer declared that for this round the max card value is 24 instead\n");
     maxcardvalue=24;
    }
    else if(dealercheating<=95&&randomeventrigger>8)
    {
        printf("The dealer declared that earning will be lower this round\n");
        winmultipler=2;
    }
    else if(dealercheating<=95&&randomeventrigger>=9)
    {
     printf("The dealer declared that for this round the max card value is 30 instead\n");
     maxcardvalue=30;
    }

     /*Betting*/
     printf("You now have %d\n",money);
     printf("How much do you want to bet?:\n");
     scanf("%d",&bet);
     if(bet>money)
     {
         printf("You cannot bet more than what you have\n");
         continue;
     }
     else if(bet==0)
     {
            printf("You decided you have enough\n");
            goto end;
     }
     else
     {
         money-=bet;
         printf("You have bet %d, you now have %d left\n",bet,money);
     }


    /*player portion*/
     dealercard1=rand()%10+1;
     card1=rand()%10+1;
     card2=rand()%9+1;
     cardvalue=card1+card2;

     printf("You received %d and %d,adding up to %d\n",card1,card2,cardvalue);
     if(cardvalue==maxcardvalue)
     {
         printf("You drew a blackjack, you win by default");
         money+=(bet*2*winmultipler);
         continue;
     }
     dealerblackjack=rand()%100+1;
     if(dealerblackjack>dealercheating)
     {
         printf("The dealer drew a blackjack\n");
         goto start;
     }
     printf("The dealer card is %d\n",dealercard1);

         while(decision!=2)
         {
             if(cardcounter>9&&cardvalue<=maxcardvalue)
             {
                 printf("You manage to draw 9 cards without bursting, you get an additional prize\n");
                 money+=(1.5*winmultipler*bet);
                 goto start;
             }
         printf("Your current value is %d\n",cardvalue);
         printf("Enter 1 to hit, 2 to stay,3 to raise your bet,4 to cheat and anything else to forfeit:\n");
         scanf("%d",&decision);
         if(decision==1)
         {
             anothercard=rand()%10+1;
             cardvalue+=anothercard;
             printf("You drew another card with the value %d to a total of %d\n",anothercard,cardvalue);
             cardcounter++;
             canraise=1;

         }
         else if(decision==2)
         {
             printf("you stayed at your current hand\n");
         }
         else if(decision==3&&canraise==0)
            {
             printf("You decided to raise your bet by:");
             scanf("%d",&betaddition);
                 if(betaddition>money)
             {
                 printf("You cannot bet more than what you have\n");
             }
             else
             {
                 money-=betaddition;
                 bet+=betaddition;
                 printf("You have raise the bet by %d\n",betaddition);
             }

            }
        else if(decision==4&&rng<=3)
            {
             printf("You swapped out your cards with better ones:\n");
             cardvalue=21;
            }
            else
            {
            printf("You commit an illegal action, this round is forfeited\n");
            goto start;
            }
            }
      /* dealer drawing cards*/
      dealeranother=rand()%10+1;
      dealertotal=dealercard1+dealeranother;
      while(dealertotal<=16)
      {
          dealertotal+=(rand()%10+1);
          printf("The dealer drew another card\n");
      }

      printf("The dealer reveal his hand:%d\n",dealertotal);
      /*handing out money*/
      if(cardvalue>maxcardvalue&&dealertotal>maxcardvalue)
      {
          printf("You busted,but so did the dealer, it is a draw\n");
          money+=bet;
      }
      else if(cardvalue<16)
      {
          printf("Your card value is too low,you lost your bet\n");
          losses+=bet;
      }
      else if(cardvalue>maxcardvalue)
      {
          printf("You busted,you lost your bet\n");
          losses+=bet;
      }
      else if(dealertotal>maxcardvalue)
      {
          printf("The dealer bursted! You won\n");
          money+=(winmultipler*bet);
          winning+=bet;
      }
      else if(cardvalue>dealertotal)
       {
           printf("You won!\n");
           money+=(winmultipler*bet);
           winning+=bet;
       }
      else if(cardvalue==dealertotal)
      {
          printf("Both of your value are the same, it is a draw\n");
          money+=bet;
      }
      else
      {
          printf("Your cards just arent good enough, you lost the bet\n");
          losses+=bet;
      }
 }
end:
if(money>2500)
{
printf("\nYou made a killing, the casino kicked you out for winning too much\n");
}
else if(money<10)
{
printf("You are now broke, but will be welcomed back after taking a loan from the bank.\nWe look foward to seeing you again\n");
}
else
{
    printf("You decide to leave early, maybe its for the better. You have %d$ on you\n",money);
}

printf("Your winning is:%d\nLosses:%d",winning,losses);

 }
