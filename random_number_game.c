#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator

    int randomNumber = rand() % 10 + 1;  // Generate a random number between 1 and 10
    int guess;
    int limit = 10;
    int lives = 3;
    int points = 0;
    int repeat = 1;
    char ask1[20];
    char name[100];
    printf("-------------------------------------\n");
    printf("Welcome to Guess A Random Number Game\n");
    printf("-------------------------------------\n");
    printf("\n");
    printf("Enter Your Name: ");
    fgets(name,sizeof(name),stdin);
    printf("\n");
    printf("Bot: Hey I just Picked A Random Number from 1 - 10, You have to Guess It.\n");
    printf("\n");
    printf("Bot: You have %d lives,Be carefull.\n",lives);
    printf("\n");
    while (repeat)
    {
        printf("                                                                                    __________\n");
        printf("                                                                                   Name: %s",name);
        printf("                                                                                   |Lives: %d |\n",lives);
        printf("                                                                                   |Points: %d|\n",points);
        printf("                                                                                    ---------\n");
        printf("You: ");
        scanf("%d",&guess);
        if(guess>limit){
            printf("\n");
            printf("NOTE: Pick a number between 1-10 only..\n");
            repeat = 1;
        }
        else if(guess == randomNumber && lives == 3){
            printf("\n");
            printf("Bot: DAMNNNNNN You WON on your first try!!!!\n");
            printf("\n");
            printf("Bot: Mine was %d and Your's was %d.\n",randomNumber,guess);
            printf("\n");
            points = 20;
            printf("Bot: Want to play again ?\n");
            printf("\n");
            printf("You: ");
            scanf("%s",&ask1);
            if(strcmp(ask1, "yes") == 0 || strcmp(ask1, "YES") == 0 || strcmp(ask1, "Yes") == 0){
                printf("\n");
                printf("Bot: Okieee Lets play again %s! :)\n",name);
                repeat = 1;
                printf("\n");
                printf("Bot: One more time I picked a random number between 1-10\n");
                lives = 3;
            }
            else if(strcmp(ask1, "no") == 0 || strcmp(ask1, "NO") == 0 || strcmp(ask1, "No") == 0){
                printf("\n");
                printf("Bot: Great gameplay man!!");
                printf("\n");
                printf("Bot: BA BAyeeeee %s!",name);
                printf("\n");
                printf("Total Points: %d",points);
                repeat = 0;
               
            }
            
        }
        else if(guess == randomNumber){
            printf("\n");
            printf("Bot: You Won!\n");
            printf("\n");
            printf("Bot: Mine was %d and Your's was %d.\n",randomNumber,guess);
            printf("\n");
            points = 10;
            printf("Bot: Want to play again ?\n");
            printf("\n");
            printf("You: ");
            scanf("%s",&ask1);
            if(strcmp(ask1, "yes") == 0 || strcmp(ask1, "YES") == 0 || strcmp(ask1, "Yes") == 0){
                printf("\n");
                printf("Bot: Okieee Lets play again %s! :)\n",name);
                printf("\n");
                repeat = 1;
                printf("Bot: One more time I picked a random number between 1-10\n");
                printf("\n");
                lives = 3;
            }
            else if(strcmp(ask1, "no") == 0 || strcmp(ask1, "NO") == 0 || strcmp(ask1, "No") == 0){
                printf("\n");
                printf("Bot: BA BAyeeeee %s!\n",name);
                printf("\n");
                printf("Total Points: %d",points);
                repeat = 0;
               
            }
        }
        else if(guess < randomNumber){
            lives = lives - 1;
            if(lives==0){
                printf("\n");
                printf("Bot: WRONG BRUHHHH!!!\n");
                printf("\n");
                printf("Bot: You Died..\n");
                break;
            }
            else if(points>5){
                points = points - 5;
            }
            printf("\n");
            printf("Bot: Don't Think Too low %s\n",name);
        }
        else if (guess > randomNumber){
            lives = lives - 1;
            if(lives==0){
                printf("\n");
                printf("Bot: WRONG BRUHHHHHHHHHHHHHH!!!\n");
                printf("\n");
                printf("Bot: You Died..\n");
                break;
            }
            else if(points>5){
                points = points - 5;
            }
            printf("\n");
            printf("Bot: Come back to earth, you are too high rightnow %s.\n",name);
        }   

    }
    return 0;
}
