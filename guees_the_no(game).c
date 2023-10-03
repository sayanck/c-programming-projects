//GUESS THE NUMBER GAME
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number;
    int noguess = 1;
    int guess;
    int choice;
    // helps to generate a different random number different time
    srand(time(0));
    printf("WELCOME TO THE GAME ~~ GUESS THE NUMBER \n");
     
     // a loop is being generated where diff try are given to you until an unless you guees the correct number
     do{
        number = rand()% 100 + 1;
         printf("Guess the number between 1 to 100 \n");
        do
        {
            
            scanf("%d", &guess);
            if (guess < number)
            {
                printf("Opps sorry!! Higher number please\n");
            }
            else if (guess > number)
            {
                printf("Opps sorry!! Lower number please \n");
            }
            // once you gueess the correct number it shows how many chance it took to guess it
            else
            {
                printf("Hoorahhh!! YOU HAVE GUSSED IT CORRECT IN  %d  ATTEMPT \n", noguess);
            }
            noguess++;
        } while (guess != number);
    // helps to continue or discontinue the game using a loop
    printf("TO continue THE game PRESS 1 or to DISCONTINUE THE game PRESS 0 \n");
    scanf("%d", &choice);
    
     }while(choice==1);
     printf("THANKS FOR PLAYING THE GAME");

    return 0;
}