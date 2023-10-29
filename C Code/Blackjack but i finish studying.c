#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DECK_SIZE 11

void welcome();
void prints(int no);
void clear(int array[]);
void shuffle(int array[],int length);
int betting(int money);

int main(void)
{
    srand(time(NULL));
    int money=100,numberofdraw,bet,hold,noofcard,playersum,dealersum,dealerdraw;

    int deck[11]={1,2,3,4,5,6,7,8,9,10,11};//Setting up all cards//

    int player[5]={0,0,0,0,0};//Setting up player cards//
    int dealer[10]={0,0,0,0,0,0,0,0,0,0};//Setting up player cards//

    welcome();
    printf("This version of blackjack only has cards from 1-11,no repeats\n");
    while(money>0)
    {
        shuffle(deck,DECK_SIZE);
        clear(player);
        clear(dealer);
        hold=0;
        numberofdraw=0;
        playersum=0;
        dealerdraw=0;

        bet=betting(money);
        money-=bet;
        printf("You have bet [%d], you have [%d] remaining\n",bet,money);

        player[numberofdraw]=deck[rand()%11];
        printf("You have drawn %d\n",player[numberofdraw]);
        numberofdraw++;
        player[numberofdraw]=deck[rand()%11];
        printf("You have drawn %d\n",player[numberofdraw]);
        numberofdraw++;
        noofcard=2;

        printf("Press 0 to draw card, any other value to hold:\n");
        while(hold==0&&noofcard<6)
        {
          scanf("%d",&hold);

          if(hold==0)
          {
            player[numberofdraw]=deck[rand()%11];
            printf("You have drawn %d\n",player[numberofdraw]);
            noofcard++;
            numberofdraw++;
            playersum=0;
          for(int i=0;i<5;i++)
            {
            playersum+=player[i];
            }
            printf("Total card value is %d\n",playersum);
          }
          playersum=0;
          for(int i=0;i<5;i++)
            {
            playersum+=player[i];
            }
        }
        playersum=0;
          for(int i=0;i<5;i++)
            {
            playersum+=player[i];
            }

        printf("Total card value is %d\n",playersum);


        printf("The dealer is drawing\n");


        while(dealersum<16&&numberofdraw<10)
        {
            dealer[numberofdraw]=deck[rand()%11];
            printf("Dealer have drawn %d\n",dealer[numberofdraw]);
            noofcard++;
            numberofdraw++;
            dealersum=0;
             for(int i=0;i<10;i++)
            {
                dealersum+=dealer[i];

            }
        }
        printf("Dealer drew a total of %d\n",dealersum);

        if(dealersum>21 && playersum<=21)
        {
            printf("The dealer busted\n");
            money+=bet*2;
        }
        else if(dealersum<=21 && playersum>21)
        {
            printf("You busted!\n");
        }
        else if(playersum>dealersum)
        {
            printf("Your value is higher than the dealer\n");
            money+=bet*2;
        }
        else
        {
            printf("Unfortunately you did not win this round\n");
        }
        printf("You have [%d] remaining\n",money);
    }

}



void prints(int no)
{
    int counter=0;
    for(counter=0;counter<no;counter++)
    {
        printf("=");
    }
    printf("\n");
}


void welcome()
{
    prints(26);
    printf("WELCOME TO AH LONG CASINO\n");
    prints(26);
}

void clear(int array[]) //Function to clear array//
{
    for(int i=0;i<5;i++)
    {
        *(array+i)=0;
    }
    return;
}

void shuffle(int array[],int length)
{
    for(int i=0;i<length;i++)
    {
        int swap_index=rand()%length;
        int temp = array[i];
        array[i]=array[swap_index];
        array[swap_index]=temp;
    }
    return;
}

int betting(int money)
{
    int bet;
        do
        {
            printf("How much would you like to bet\n");
            scanf("%d",&bet);
            if(bet>money)
            {
                printf("You cannot bet more than what you have\n");
            }
            if(bet==0)
            {
                printf("You cannot play for free!\n");
            }
        }
        while(bet>money || bet==0);
    return bet;
}
