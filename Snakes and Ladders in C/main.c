#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int dice;
int checkposition();
int position, newposition;
int choice, count=0;

void main()
{
    printf("Would you like to:\n  1. Read the rules\n  2. Play the game\n  3. Close the game\n\n");
    //menu of the application where the options are: to read the rules, to play the game and to close the game
    scanf("%d", &choice);
    if(choice==1)
    {
        printf("\nThe rules are simple:\n You press enter to roll the dice! "
               "\nIf you land on a ladder, you will get to the position of the end of the ladder. "
               "\nIf you land on a snake, you will get to the position where the tail of the snake is."
               "\nYou win the game once you get to 100!");//explanation of rules
    }
    if(choice==2) {
        printf("Welcome to Snakes and Ladders \n");
        printf(" | 91  92  93  94  95  96  97  98  99  100 |     1 = START               3 = Ladder to 51\n");
        printf(" | 81  82  83  84  85  86  87  88  89  90  |     6 = Ladder to 27        20 = Ladder to 70\n");
        printf(" | 71  72  73  74  75  76  77  78  79  80  |     25 = Snake to 5         34 = Snake to 1\n");
        printf(" | 61  62  63  64  65  66  67  68  69  70  |     36 = Ladder to 55       47 = Snake to 19\n");
        printf(" | 51  52  53  54  55  56  57  58  59  60  |     63 = Ladder to 95       65 = Snake to 52\n");
        printf(" | 41  42  43  44  45  46  47  48  49  50  |     68 = Ladder to 98       87 = Snake to 57\n");
        printf(" | 31  32  33  34  35  36  37  38  39  40  |     91 = Snake to 61        99 = Snake to 69\n");
        printf(" | 21  22  23  24  25  26  27  28  29  30  |     100 = END\n");
        printf(" | 11  12  13  14  15  16  17  18  19  20  |                    \n");
        printf(" |  1   2   3   4   5   6   7   8   9  10  |                    \n");
        printf("**WINNER WILL BE THE ONE WHO GETS TO 100 FIRST! THAT IS WITH MINIMUM NUMBER OF DICE THROWS...\n");
        //presenting the game table, the position of where you land and the equivalent of the new position
        do {
            printf("\n\n Press any key to roll the dice\n\n");
            dice -= (getche());
            dice = ((rand() % 6) + 1);
            printf("You rolled a %d",dice);
            position += dice;
            //how the dice works, using the random function
            if (dice == 6)
            {
                printf("\n6 came up on the dice throw!! You can get one more throw! \n");
                printf("\nYou landed on number %d!\n", position);
                continue;
            }
            //if you throw a six, you have the chance to throw again
            printf("\nYou landed on number %d!\n", position);
            count++;
            checkposition();//calling the function for checking either being on a ladder, or a snake
            position = newposition;//getting to the new position after rolling the dice
        } while (position < 100);
        printf("Congratulation, you have won! in %d dice throws\n", count);
    }
    if(choice==3)
        return 0;
    getch();
    //closes the game if 3 is pressed
}

checkposition()
{
    switch (position)
    {
        case 3:
            newposition = 51;
            {
                printf("\nWell done! You have landed on a ladder! You are now on space %d!\n", newposition);
                break;
            }
        case 6:
            newposition = 27;
            {
                printf("\nWell done! You have landed on a ladder! You are now on space %d!\n", newposition);
                break;
            }
        case 20:
            newposition = 70;
            {
                printf("\nWell done! You have landed on a ladder! You are now on space %d!\n", newposition);
                break;
            }
        case 25:
            newposition = 5;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        case 34:
            newposition = 1;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        case 36:
            newposition = 55;
            {
                printf("\nWell done! You have landed on a ladder! You are now on space %d!\n", newposition);
                break;
            }
        case 47:
            newposition = 19;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        case 63:
            newposition = 95;
            {
                printf("\nWell done! You have landed on a ladder! You are now on space %d!\n", newposition);
                break;
            }
        case 65:
            newposition = 52;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        case 68:
            newposition = 98;
            {
                printf("\nWell done! You have landed on a ladder! You are now on space %d!\n", newposition);
                break;
            }
        case 87:
            newposition = 57;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        case 91:
            newposition = 61;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        case 99:
            newposition = 69;
            {
                printf("\nUnlucky! You have landed on a Snake! You are now on space %d!\n", newposition);
                break;
            }
        default:
            return newposition = position;
    }
    //function for checking if the player has landed on a ladder or on a snake
}
