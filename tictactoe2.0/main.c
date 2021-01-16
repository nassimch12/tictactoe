#include <stdio.h>
#include <stdlib.h>
int checkforwin();
void displayboard();
void markboard(int sign);

int player, choice;
char board[3][3] ={{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};

void main()
{
  player=1;
  int game = -1;
  char sign;

  do{

    displayboard();
    player = (player %2 )? 1 : 2;
    printf("player %i , choose a number : ",player);
    scanf("%i",&choice);

    sign=(player==1)? 'X' : 'O';
    markboard(sign);
    game=checkforwin();
    player++;

  }while(game==-1);

  if(game==1)
    printf("player %i wins!!!",--player);
  else printf("game is a draw!!!");

}

void displayboard()
{
    system("cls");

    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0][0], board[0][1],board[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[2][0], board[2][1] , board[2][2]);

    printf("     |     |     \n\n");
}

void markboard(int sign)
{
 if (choice == 1 && board[0][0]=='1')
    board[0][0] = sign;
 else if (choice == 2 && board[0][1]=='2')
    board[0][1]=sign;
 else if (choice == 3 && board[0][2]=='3')
    board[0][2]=sign;
 else if (choice == 4 && board[1][0]=='4')
    board[1][0]=sign;
 else if (choice == 5 && board[1][1]=='5')
    board[1][1]=sign;
 else if (choice == 6 && board[1][2]=='6')
    board[1][2]=sign;
 else if (choice == 7 && board [2][0]=='7')
    board[2][0]=sign;
 else if(choice == 8 && board[2][1]=='8')
    board[2][1]=sign;
 else if (choice == 9 && board[2][2]=='9')
    board[2][2]=sign;
 else {
        printf("invalid choice");

        player--;
        getch();
      }

}

int checkforwin()
{
    int returnValue = 0;

    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
    {
        returnValue = 1;
    }
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        returnValue = 1;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        returnValue = 1;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        returnValue = 1;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        returnValue = 1;

    else if (board[0][2] == board[1][2] && board[1][2]==board[2][2])
        returnValue = 1;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        returnValue = 1;

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        returnValue = 1;

    else if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
        board[1][0] != '4' && board[1][1]  != '5' && board[1][2]  != '6' && board[2][0]
        != '7' && board[2][1] != '8' && board[2][2] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}


