/* Written by: Umang Rathod */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void setup_board();                  // Complexity O(n^2)
void display_board();                // Complexity O(n^2)
void set_coords_to();                // Complexity(1)
void set_coords_from();              // Complexity(1)
void move_validation_and_updation(); // Complexity(n)
void play_game();
int king(); // Complexity O(n^2)

// Functions For Pieces Ability To Move
void WhitePawn();
void BlackPawn();
void WhiteRook();
void BlackRook();
void Knight();
void Bishop();
void KingKing();
void Queen();

// Global Variables
char piece_moved;
char board[10][10];
char move[5];
char choice;
short x, y, a, b;
int i = 0;

// Created By : Umang Rathod
int main()
{
    char choice;
    int j, asc1, asc2, s = 10;

    setup_board();

    printf("Enter Y to start the game : ");
    scanf("%c", &choice);

    if (choice != 'Y')
    {
        printf("Come After Sometime");
        return 0;
    }
    printf("Game Begin Players");
    printf("\n\n");
    display_board();

    while (king() == 10)
    {
        play_game();
    }
    return 0;
}

// Created By : Vikram Kumar
// Complexity O(n^2)
void display_board()
{
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

// Created By : Yashwanth
// Complexity O(n^2)
int king()
{
    int i, j, temp1 = 0, temp2 = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (board[i][j] == 'k')
            {
                temp1 = 5;
            }
            if (board[i][j] == 'K')
            {
                temp2 = 5;
            }
        }
    }
    if (temp1 == 0)
    {
        printf("White (Capital) has won the game");
        return 0;
    }
    if (temp2 == 0)
    {
        printf("Black(Small) has won the game");
        return 0;
    }

    temp1 = 0;
    temp2 = 0;
    return 10;
}

// Created By : Jimit Patel
// Complexity O(n^2)
void setup_board()
{
    for (x = 0; x < 8; x++)
    {
        for (y = 0; y < 9; y++)
        {
            board[x][y] = '-';
        }
    }

    // upper pieces
    board[0][1] = 'r';
    board[0][2] = 'n';
    board[0][3] = 'b';
    board[0][4] = 'q';
    board[0][5] = 'k';
    board[0][6] = 'b';
    board[0][7] = 'n';
    board[0][8] = 'r';

    board[1][1] = 'p';
    board[1][2] = 'p';
    board[1][3] = 'p';
    board[1][4] = 'p';
    board[1][5] = 'p';
    board[1][6] = 'p';
    board[1][7] = 'p';
    board[1][8] = 'p';

    // Lower Moves
    board[7][1] = 'R';
    board[7][2] = 'N';
    board[7][3] = 'B';
    board[7][4] = 'Q';
    board[7][5] = 'K';
    board[7][6] = 'B';
    board[7][7] = 'N';
    board[7][8] = 'R';

    board[6][1] = 'P';
    board[6][2] = 'P';
    board[6][3] = 'P';
    board[6][4] = 'P';
    board[6][5] = 'P';
    board[6][6] = 'P';
    board[6][7] = 'P';
    board[6][8] = 'P';

    // Notation Help
    board[9][0] = '+';
    board[7][0] = '1';
    board[6][0] = '2';
    board[5][0] = '3';
    board[4][0] = '4';
    board[3][0] = '5';
    board[2][0] = '6';
    board[1][0] = '7';
    board[0][0] = '8';

    board[9][1] = 'A';
    board[9][2] = 'B';
    board[9][3] = 'C';
    board[9][4] = 'D';
    board[9][5] = 'E';
    board[9][6] = 'F';
    board[9][7] = 'G';
    board[9][8] = 'H';
}

// Created By : Yogesh Kumar
// Complexity O(1)
void set_coords_to()
{

    // Get Y value from character

    if (strchr(move, 'a'))
    {
        y = 1;
    }
    else if (strchr(move, 'b'))
    {
        y = 2;
    }
    else if (strchr(move, 'c'))
    {
        y = 3;
    }
    else if (strchr(move, 'd'))
    {
        y = 4;
    }
    else if (strchr(move, 'e'))
    {
        y = 5;
    }
    else if (strchr(move, 'f'))
    {
        y = 6;
    }
    else if (strchr(move, 'g'))
    {
        y = 7;
    }
    else if (strchr(move, 'h'))
    {
        y = 8;
    }

    // get X value from character
    if (strchr(move, '8'))
    {
        x = 0;
    }
    else if (strchr(move, '7'))
    {
        x = 1;
    }
    else if (strchr(move, '6'))
    {
        x = 2;
    }
    else if (strchr(move, '5'))
    {
        x = 3;
    }
    else if (strchr(move, '4'))
    {
        x = 4;
    }
    else if (strchr(move, '3'))
    {
        x = 5;
    }
    else if (strchr(move, '2'))
    {
        x = 6;
    }
    else if (strchr(move, '1'))
    {
        x = 7;
    }
}

// Created By : Yogesh Kumar
// Complexity O(1)
void set_coords_from()
{

    // B value
    // a = row
    // b = column

    if (strchr(move, 'a'))
    {
        b = 1;
    }
    else if (strchr(move, 'b'))
    {
        b = 2;
    }
    else if (strchr(move, 'c'))
    {
        b = 3;
    }
    else if (strchr(move, 'd'))
    {
        b = 4;
    }
    else if (strchr(move, 'e'))
    {
        b = 5;
    }
    else if (strchr(move, 'f'))
    {
        b = 6;
    }
    else if (strchr(move, 'g'))
    {
        b = 7;
    }
    else if (strchr(move, 'h'))
    {
        b = 8;
    }

    // A value
    if (strchr(move, '8'))
    {
        a = 0;
    }
    else if (strchr(move, '7'))
    {
        a = 1;
    }
    else if (strchr(move, '6'))
    {
        a = 2;
    }
    else if (strchr(move, '5'))
    {
        a = 3;
    }
    else if (strchr(move, '4'))
    {
        a = 4;
    }
    else if (strchr(move, '3'))
    {
        a = 5;
    }
    else if (strchr(move, '2'))
    {
        a = 6;
    }
    else if (strchr(move, '1'))
    {
        a = 7;
    }
}

// Created By : Umang Rathod
// Complexity O(n)
void move_validation_and_updation()
{
    int k, temp = 0;
    switch (piece_moved)
    {
    // pawn pieces
    // Created By : Manoj Kumar
    case 'p':
    {
        BlackPawn();
    }
    break;

    case 'P':
    {
        WhitePawn();
    }
    break;

    // Rook pieces
    // Created By : Yogesh Kumar
    case 'r':
    {
        BlackRook();
    }
    break;

    case 'R':
    {
        WhiteRook();
    }
    break;

    // Created By : Garv Chauhan
    // Knight
    case 'n':
    {
        Knight();
    }
    break;

    case 'N':
    {
        Knight();
    }
    break;

    // Created By :Vikas Bishnoi
    // Case for bishop
    case 'b':
    {
        Bishop();
    }
    break;

    case 'B':
    {
        Bishop();
    }
    break;

    // Created By : Kaushik Rathva
    // Queen pieces
    case 'q':
    {
        Queen();
    }
    break;

    case 'Q':
    {
        Queen();
    }
    break;

    // Created By : Maniyar Aamer
    // King programming
    case 'k':
    {
        KingKing();
    }
    break;

    case 'K':
    {
        KingKing();
    }
    break;
    }
}

//-------------------------------------------Pieces Move-----------------------------------------------------//
// Created By : Manoj Kumar
// Pawn Pieces
void WhitePawn()
{
    if (abs(x - a) == 1)
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else if (a == 6 && abs(x - a) == 2)
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else if (board[x][y] != '-' && abs(a - x) == 1 && abs(b - y) == 1)
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}
void BlackPawn()
{
    if (abs(x - a) == 1 && board[x][y] == '-')
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else if (a == 1 && abs(x - a) == 2 && board[x][y] == '-')
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else if (board[x][y] != '-' && abs(a - x) == 1 && abs(b - y) == 1)
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}

// Created By : Maniyar Aamer
// Rook Pieces
void BlackRook()
{
    int temp = 0;
    if (a - x == 0 || b - y == 0)
    {
        if (a - x == 0)
        {
            for (int k = 1; k < abs(b - y); k++)
            {
                if (b > y && board[a][a - k] != '-')
                {
                    temp = 5;
                }
                else if (b < y && board[a][b + k] != '-')
                {
                    temp = 5;
                }
            }
        }
        if (b - y == 0)
        {
            for (int k = 1; k < abs(a - x); k++)
            {
                if (a > x && board[a - k][b] != '-')
                {
                    temp = 5;
                }
                else if (a < x && board[a + k][b] != '-')
                {
                    temp = 5;
                }
            }
        }
        if (temp == 0)
        {
            board[x][y] = piece_moved;
            board[a][b] = '-';
        }
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}
void WhiteRook()
{
    int temp = 0, k;
    if (a - x == 0 || b - y == 0)
    {
        if (a - x == 0)
        {
            for (k == 1; k < abs(b - y); k++)
            {
                if (b > y && board[a][b - k] != '-')
                {
                    temp = 5;
                }
                else if (b < y && board[a][b + k] != '-')
                {
                    temp = 5;
                }
            }
        }
        if (temp == 0)
        {
            board[x][y] = piece_moved;
            board[a][b] = '-';
        }
        else
        {
            printf("Invalid Move Try Again");
            i--;
        }
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}

// Created By : Vikram Kumar
// Knight Pieces
void Knight()
{
    if ((abs(a - x) == 2 && abs(b - y) == 1) || (abs(a - x) == 1 && abs(b - y) == 2))
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}

// Created By : Vikas Bishnoi
// Bishop Pieces
void Bishop()
{
    int k, temp = 0;
    if (abs(a - x) == abs(b - y) && (a - x) != 0)
    {
        for (k = 1; k < abs(a - x); k++)
        {
            if (a > x && b < y && board[a - k][b + k] != '-')
            {
                temp = 5;
            }
            else if (a < x && b > y && board[a + k][b - k] != '-')
            {
                temp = 5;
            }
            else if (a < x && b < y && board[a + k][b + k] != '-')
            {
                temp = 5;
            }
            else if (a > x && b > y && board[a - k][b - k] != '-')
            {
                temp = 5;
            }
        }
        if (temp == 0)
        {
            board[x][y] = piece_moved;
            board[a][b] = '-';
        }
        else
        {
            printf("Invalid Move Try Again");
            i--;
        }
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}

// Created By : Kaushik Rathva
// Queen Pieces
void Queen()
{
    int k, temp = 0;
    if ((abs(a - x) == abs(b - y)) && a - x != 0)
    {
        for (k = 1; k < (a - x); k++)
        {
            if (a > x && b < y && board[a - k][b + k] != '-')
            {
                temp = 5;
            }
            else if (a < x && b > y && board[a + k][b - k] != '-')
            {
                temp = 5;
            }
            else if (a < x && b < y && board[a + k][b + k] != '-')
            {
                temp = 5;
            }
            else if (a > x && b > y && board[a - k][b - k] != '-')
            {
                temp = 5;
            }
        }
        if (b - y == 0)
        {
            for (k = 1; k < (a - x); k++)
            {
                if (a > x && board[a - k][b] != '-')
                {
                    temp = 5;
                }
                else if (a < x && board[a + k][b] != '-')
                {
                    temp = 5;
                }
            }
        }
        if (temp == 0)
        {
            board[x][y] = piece_moved;
            board[a][b] = '-';
        }
        else
        {
            printf("Invalid Move Try Again");
            i--;
        }
    }
    else
    {
        printf("Invalid Move Try Again");
        i--;
    }
}

// Created By : Garv Chauhan
// King Pieces
void KingKing()
{
    int temp = 0;
    if (abs(a - x) <= 1 && abs(b - y) <= 1)
    {
        board[x][y] = piece_moved;
        board[a][b] = '-';
    }
    else
    {
        printf("\n\nInvalid Move Try Again");
        i--;
        temp = 0;
    }
}

//-------------------------------------------------Play Game------------------------------------------------//
// Created By : Garv Chauhan
void play_game()
{
    printf("Enter Move From : ");
    scanf("%s", &move);
    set_coords_from(); // a,b store
    piece_moved = board[a][b];

    printf("Enter Move To :");
    scanf("%s", &move);
    set_coords_to(); // x,y store

    int asc1 = board[a][b];
    int asc2 = board[x][y];

    // White ()
    if (i % 2 == 0)
    {
        if (64 < asc1 && asc1 < 91)
        {
            if (64 < asc2 && asc2 < 91)
            {
                printf("\nU cat kill your own pieces\n");
                i--;
            }
            else
            {
                move_validation_and_updation();
            }
        }
        else
        {
            printf("\nCapitals Are White And U can Only Move Your Pieces\n");
            i--;
        }
    }
    // Small
    else if (i % 2 == 1)
    {
        if (97 < asc1 && asc1 < 123)
        {
            if (97 < asc2 && asc2 < 123)
            {
                printf("\nU cat kill your own pieces\n");
                i--;
            }
            else
            {
                move_validation_and_updation();
            }
        }
        else
        {
            printf("\nSmall Are Black And U can Only Move Your Pieces\n");
            i--;
        }
    }

    printf("\n");
    display_board();
    i++;
}