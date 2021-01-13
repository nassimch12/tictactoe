#include <stdio.h>
#include <stdlib.h>

char table[10] ={'0','1','2','3','4','5','6','7','8','9'};
int choice,player;

int checkforwin();
void fillboard(char sign);
void drawtable();

void main()
{
   char sign;
   int game;

   player = 1;

   do{

    drawtable();

    if( (player % 2 )== 0)       //changing turns
        player = 2;
    else player = 1;

    printf("player number %i s turn : ",player);
    scanf("%i",&choice);

    if(player == 1)         //assigning sign
        sign = 'X';
    else sign = 'O';

    fillboard(sign);

    game = checkforwin();

    player++;

   }while(game == -1);


   // result

   if(game == 1)
   {player--;
    printf("!!!player number %i wins!!!",player);}
   else
      printf("game over : draw!");


}


void drawtable()
{
    system("cls");

    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", table[1], table[2], table[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", table[4], table[5], table[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", table[7], table[8], table[9]);

    printf("     |     |     \n\n");
}

//1 win
//-1 still on
//0 draw
int checkforwin()
{

    int value = 0;

    if(table[1]==table[2] && table[2]==table[3])
        value = 1;
    else if((table[1]==table[4])&&(table[4]==table[7]))
        value = 1;
    else if((table[7]==table[8])&&(table[8]==table[9]))
        value = 1;
    else if((table[3]==table[6])&&(table[6]==table[9]))
        value = 1;
    else if((table[1]==table[5])&&(table[5]==table[9]))
        value = 1;
    else if((table[7]==table[5])&&(table[5]==table[3]))
        value = 1;
    else if((table[4]==table[5])&&(table[5]==table[6]))
        value = 1;
    else if((table[2]==table[5])&&(table[5]==table[8]))
        value = 1;
    else if(table[1]!='1'&& table[2]!='2' && table[3]!='3'&& table[4]!='4'&& table[5]!='5'&&
            table[6]!='6' && table[7]!='7' && table[8]!='8' && table[9]!='9')
                value = 0;
    else value = -1;

    return value;

}
//fill board with sign
//sign = X or O
void fillboard(char sign)
{
    if(choice == 1 && table[1]=='1')
        table[1] = sign;
    else if(choice == 2 && table[2]=='2')
        table[2] = sign;
    else if (choice == 3 && table[3]=='3')
        table[3] = sign;
    else if (choice == 4 && table[4]=='4')
        table[4] = sign;
    else if (choice == 5 && table[5]=='5')
        table[5] = sign;
    else if (choice == 6 && table[6]=='6')
        table[6] = sign;
    else if (choice == 7 && table[7]=='7')
        table[7] = sign;
    else if (choice == 8 && table[8]=='8')
        table[8] = sign;
    else if (choice == 9 && table[9]=='9')
        table[9] = sign;
    else
    {
        printf("invalid move! press to try again");

        player--;
        getch();

    }
}
