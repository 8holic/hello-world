#import <stdio.h> //Needed for all//
#import <time.h>  //Needed for seed//
#import <stdlib.h>//For rand()//
#import <time.h>  //For time()//

int main(void)
{
    int min,max,actual,guess,counter = 1,i,flag=0,proximity,guesses;

    srand((unsigned) time(NULL));

    //generating a random value//
    actual = rand() % 300 + rand()%rand();
    min = actual - rand()%3000;
    max = actual + rand()%3000;
    printf("The mininum number is %d while the maxinum number is %d\n",min,max);

    //hints//
    printf("Hints:\n");
    switch(actual%2)
    {
        case 0: printf("The number is even\n");
        break;
        case 1: printf("The number is odd\n");
        break;
    }

    for(counter=2;counter<actual;counter++)
    {
        if(actual % counter == 0)
        {
            flag=1;
        }
    }
    switch(flag)
    {
        case 0:printf("The number is prime\n");
        break;
        case 1:printf("The number is not prime\n");
        break;
    }
    proximity = actual/100;
    //guessing//
    printf("Please guess a number: ");
    scanf("%d",&guess);
    while(guess!=actual)
    {
        if(guess<min || guess > max)
            printf("Your value is outside the given range of %d and %d\n",min,max);
        else
        {
            if(actual>guess)
            {
                printf("Your number is too small\n");
            }
            else if(actual<guess)
            {
                printf("Your number is too large\n");
            }
            else
            {
                printf("Your input is invalid\n");
            }

            if((float)guess/actual>1.5)
            {
                printf("Your value is more than 1.5 times away the actual value\n");
            }
            else if((float)guess/actual<0.5)
            {
                printf("Your value is more than 0.5 times away the actual value\n");
            }

            if(guess-actual<proximity && guess-actual>-proximity)
            {
                printf("Your value is within %d from the actual value! Your are close\n",proximity);
            }
        }


        printf("\nPlease guess another number: ");
        scanf("%d",&guess);
        fflush(stdin);
        guesses ++;
    }
printf("You got the correct number! The number is %d\nIt took you %d guesses",actual,guesses);


    return 0;
}




