
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0

int ROCK_PAPER_SCISSOR(int player1,int player2)
{
    int result;
    if(player1==ROCK && player2==PAPER)
    {
        result = PLAYER2_WIN;
    }
    else if(player1==ROCK && player2==SCISSOR)
    {
        result = PLAYER1_WIN;
    }
    else if(player1==PAPER && player2==ROCK)
    {
        result = PLAYER1_WIN;
    }
    else if(player1==PAPER && player2==SCISSOR)
    {
       result = PLAYER2_WIN;
    }
    else if(player1==SCISSOR && player2==ROCK)
    {
        result = PLAYER2_WIN;
    }
    else if(player1==SCISSOR && player2==PAPER)
    {
        result = PLAYER1_WIN;
    }
    else
    {
        result = DRAW;
    }
    return result;
}

int get_user_input()
{
    int choice;
    do
    {
        printf("1.Rock\n");
        printf("2.Paper\n");
        printf("3.Scissor\n");
        printf("please input [1,2,3] : ");
        scanf("%d",&choice);
        if(!(choice>=1 && choice<=3))
        {
            printf("ERROR -- Invalid input, should be 1 or 2 or 3");
        }
    }
        while(!(choice>=1 && choice<=3));


    return choice;
}
void print_word(int v)
{
    if(v==ROCK)
    {
        printf("Rock\n");
    }
    else if(v==PAPER)
    {
        printf("Paper\n");
    }
    else if(v==SCISSOR)
    {
        printf("Scissor\n");
    }

}

int main()
{
    int user_SCORE = 0;
    int Computer_SCORE = 0;
    srand(time(NULL));
    int quit =0;
    while(!quit)
    {
        int user_input = get_user_input();
        int Computer_choice = (rand()%3)+1;
        printf("Computer chose: ");
        print_word(Computer_choice);
        printf("user chose : ");
        print_word(user_input);
        int result = ROCK_PAPER_SCISSOR(user_input,Computer_choice);
        if(result == DRAW)
        {
            printf("\n\nIt is a Draw!!!!!!!\n\n");
        }
        else if(result == PLAYER1_WIN)
        {
            printf("\n\nuser defeated the computer and won the round!!!!!!!!!\n\n");
            user_SCORE++;
        }
        else if(result == PLAYER2_WIN)
        {
            printf("\n\n computer won the round shittttt! \n\n");
            Computer_SCORE++;
        }
        printf("\n");
        printf("**************************************\n");
        printf("user score : %d\n",user_SCORE);
        printf("Computer score : %d\n",Computer_SCORE);
        printf("***************************************\n");
        printf("\n\n");
        printf(" if you want to continue the game please input any integer else enter ZERO(0) to terminate .");
        int response;
        scanf("%d",&response);
        if(response == 0)
        {
            quit = 1;
        }
    }
    printf("\n\nFinal score.......\n");
    printf("\n");
    printf("*************************************************\n");
    printf("user Score : %d\n\n",user_SCORE);
    printf("Computer Score : %d\n\n",Computer_SCORE);
    printf("*************************************************\n");
    printf("\n\n");
    if(user_SCORE == Computer_SCORE)
    {
        printf("GAME WAS DRAW\n");
    }
    else if(user_SCORE > Computer_SCORE)
    {
        printf("user won the game yeeeeeeaaaaaaah!\n");
    }
    else if(user_SCORE < Computer_SCORE)
    {
        printf("shittt! computer won the game\n");
    }
    return 0;
}
