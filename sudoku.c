#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void trophy()
{
    system("cls");
    system("color 0E");
    printf("         YOU WON CONGRATULATIONS!!!\n");
    printf("----------------------------------------\n");
    printf("          .-=========-.               \n");
    printf("          \\'-=======-'/               \n");
    printf("          _|   .=.   |_               \n");
    printf("         ((|  {{1}}  |))              \n");
    printf("          \\|   /|\\   |/               \n");
    printf("           \\__ '`' __/                \n");
    printf("             _`) (`_                  \n");
    printf("           _/_______\\_                \n");
    printf("          /___________\\\n----------------------------------------");
    Sleep(5000);
}

void print(int combination[9][9])
{
    system("cls");
    int i, j;
    char space = '-'; // we use it in place of the zeros in the predefined matrix
    system("color 0A");
    printf("\n-------------------------SUDOKU--------------------------\n");
    printf("      0    1    2       3    4    5       6    7    8\n");
    printf("---------------------------------------------------------\n");
    for (i = 0; i < 9; i++)
    {
        if (i == 3)
        {
            printf("\n");
        }
        if (i == 6)
        {
            printf("\n");
        }                    // formatting the matrix, press enter every three lines to divide it
        printf("%d |  ", i); // matrix formatting, insert the line number and | to separate from the matrix
        for (j = 0; j < 9; j++)
        {
            if (j == 3)
            {
                printf(" | "); // matrix formatting, in the 3rd column inserts this | to separate from the other block of columns
            }
            if (j == 6)
            {
                printf(" | "); // matrix formatting, in the 6th column inserts this | to separate from the other block of columns
            }
            if (combination[i][j] == 0)
            {
                printf(" %c   ", space);
            } // here it replaces the zero with the character -
            else
            {
                printf(" %d   ", combination[i][j]);
            } // If it doesn't have 0 it just prints normally
        }
        printf("|");
        printf("\n");
    }
}

void game_check(int combination[9][9])
{                       // function of the game that receives the chosen matrix
    int cont = 0;       // counter for the game to run while the matrix is ​​not completely filled
    int original[9][9]; // original matrix to compare with the matrix where the user will change the values
    int maximum_number_of_columns = 0;
    int maximum_number_of_rows = 0;
    int l = 0;
    int c = 0;
    int give_up = 1;
    int i, j, i1, j1, i2, j2;
    system("cls");
    for (i1 = 0; i1 < 9; i1++)
    { // here creates the original matrix with the predefined values ​​of the drawn matrix before being changed
        for (j1 = 0; j1 < 9; j1++)
        {
            original[i1][j1] = combination[i1][j1];
        }
    }

    while (cont < 81)
    {
        int row, column, value; // values ​​that the user enters

        print(combination);
        printf("---------------------------------------------------------\n");
        printf("To give_up enter -999- any time\n");
        printf("---------------------------------------------------------\n");
        printf("In which row and column do you want to insert a value?");
        printf("\nrow: ");
        scanf("%d", &row);

        if (row == 999)
        {
            system("color 0C");
            printf("\nSEE YOU QUIT! GOOD LUCK NEXT TIME\n");
            Sleep(2000);
            break;
        }
        while (row < 0 || row > 8 && row <= 998 || row > 999)
        {
            system("color 0C");
            printf("\nThe row MUST BE BETWEEN 0 AND 8!\n");
            Sleep(2000);
            system("color 0A");
            printf("\nInsert the row again: \n");
            scanf("%d", &row);
        }
        if (row == 999)
        {
            system("color 0C");
            printf("\nSEE YOU QUIT! GOOD LUCK NEXT TIME\n");
            Sleep(2000);
            break;
        }

        printf("column: ");
        scanf("%d", &column);
        if (column == 999)
        {
            system("color 0C");
            printf("\nSEE YOU QUIT! GOOD LUCK NEXT TIME\n");
            Sleep(2000);
            break;
        }
        while (column < 0 || column > 8 && column <= 998 || column > 999)
        {
            system("color 0C");
            printf("\nThe column MUST BE BETWEEN 0 AND 8!\n");
            Sleep(2000);
            system("color 0A");
            printf("\nInsert the column again: \n");
            scanf("%d", &column);
        }
        if (column == 999)
        {
            system("color 0C");
            printf("\nSEE YOU QUIT! GOOD LUCK NEXT TIME\n");
            Sleep(2000);
            break;
        }

        printf("What is the value?\n");
        scanf("%d", &value);
        if (value == 999)
        {
            system("color 0C");
            printf("\nSEE YOU QUIT! GOOD LUCK NEXT TIME\n");
            Sleep(2000);
            break;
        }
        while (value <= 0 || value > 9 && value <= 998 || value > 999)
        {
            system("color 0C");
            printf("\nThe value MUST BE BETWEEN 1 and 9!\n");
            Sleep(2000);
            system("color 0A");
            printf("\nInsert the value again: \n");
            scanf("%d", &value);
        }
        if (value == 999)
        {
            system("color 0C");
            printf("\nSEE YOU QUIT! GOOD LUCK NEXT TIME\n");
            Sleep(2000);
            break;
        }

        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                // the following conditions serve to save rows of code,
                // where the values ​​to be used in the comparison will be defined
                // quadrant later
                if (row >= 0 && row < 3)
                {
                    l = 0;
                    maximum_number_of_rows = 2;
                    // here for example, if the user types row 1 it sets these values
                    // to compare only within that range, along with as colmuns
                }

                else if (row >= 3 && row < 6)
                {
                    l = 3;
                    maximum_number_of_rows = 5;
                }

                else if (row >= 6 && row < 9)
                {
                    l = 6;
                    maximum_number_of_rows = 8;
                }

                if (column >= 0 && column < 3)
                {
                    c = 0;
                    maximum_number_of_columns = 2;
                    // the same as with rows,
                    // only with columns, like this
                    // creates a "matrix" with these values
                }

                else if (column >= 3 && column < 6)
                {
                    c = 3;
                    maximum_number_of_columns = 5;
                }

                else if (column >= 6 && column < 9)
                {
                    c = 6;
                    maximum_number_of_columns = 8;
                }

                // in this case we will use the values ​​defined above so that
                // we can compare a small 3x3 matrix (quadrant)
                for (l = l; l <= maximum_number_of_rows; l++)
                {
                    int c1 = c;
                    // we created this c1 here because we were having a problem:
                    // in row X it compared with the values ​​in column X, Y and Z
                    // but in the next rows Y and Z the column values ​​are not
                    // were reset because they were like "c = c", in this way
                    // we had to put c1 = c, so every time it does
                    // the column x y and z it went back to the next row and reset
                    // c1 to x, to be able to do y and z again
                    for (c1 = c1; c1 <= maximum_number_of_columns; c1++)
                    {

                        if (original[l][c1] != 0 && l == row && c1 == column)
                        { // if the value is predefined it does not change
                            system("color 0C");
                            printf("\n------------------------------");
                            printf("\n| YOU CANNOT CHANGE HERE |\n");
                            printf("------------------------------\n");
                            i = 9;
                            j = 9;
                            Sleep(2000);
                        }
                        if (combination[l][c1] == value && i == 0)
                        { // see if the value is already in the array
                            system("color 0C");
                            printf("\n--------------------------------------");
                            printf("\n| THAT NUMBER ALREADY EXISTS IN THE QUADRANT |\n");
                            printf("--------------------------------------\n");
                            l = maximum_number_of_rows;
                            c1 = maximum_number_of_columns;
                            i = 9;
                            j = 9;
                            Sleep(2000);
                        }
                        if (l == maximum_number_of_rows && c1 == maximum_number_of_columns)
                        {
                            if (combination[row][j] == value)
                            { // check if the value is already in the row
                                system("color 0C");
                                printf("\n-------------------------------");
                                printf("\n| value ALREADY EXISTS IN row |\n");
                                printf("-------------------------------\n");
                                i = 9;
                                j = 9;
                                Sleep(2000);
                            }

                            else if (combination[i][column] == value)
                            { // check if the value is already in the column
                                system("color 0C");
                                printf("\n--------------------------------");
                                printf("\n| value ALREADY EXISTS IN column |\n");
                                printf("--------------------------------\n");
                                i = 9;
                                j = 9;
                                Sleep(2000);
                            }
                            else if (j == 8 && i == 8)
                            { // if the value is not in the row and column, it goes here

                                if (combination[row][column] != 0)
                                { // if player wants to enter a position that already has a number

                                    if (original[row][column] != combination[row][column])
                                    { // change only if the value is not predefined
                                        combination[row][column] = value;
                                        j = 9;
                                        i = 9;
                                    }
                                }

                                else if (combination[row][column] == 0)
                                { // if he wants to insert in an empty position and there is no number in the row or column or quadrant
                                    combination[row][column] = value;
                                    j = 9;
                                    i = 9;
                                }
                            }
                        }
                    }
                }

                cont = 0;
                for (i2 = 0; i2 < 9; i2++)
                {
                    for (j2 = 0; j2 < 9; j2++)
                    {
                        if (combination[i2][j2] != 0)
                        {
                            cont = cont + 1;
                        }
                    }
                }
            }
        }
    }
    if (cont > 80)
    {
        trophy();
    }
}

void choose_matrix(int decision_menu)
{ // so you can play on three different levels :)
    int combination0[9][9] = {
        {8, 0, 0, 0, 5, 2, 0, 0, 0},
        {0, 0, 3, 8, 4, 6, 0, 7, 5},
        {0, 7, 5, 9, 0, 1, 0, 0, 0},
        {0, 5, 1, 3, 0, 4, 6, 0, 0},
        {0, 8, 6, 5, 2, 0, 0, 1, 7},
        {2, 9, 4, 1, 0, 0, 0, 8, 3},
        {0, 1, 0, 4, 7, 0, 0, 0, 0},
        {4, 0, 7, 2, 9, 5, 0, 0, 8},
        {5, 0, 0, 6, 0, 8, 0, 4, 9}};
    int combination1[9][9] = {
        {0, 8, 6, 4, 0, 7, 2, 0, 9},
        {0, 0, 0, 5, 1, 0, 0, 0, 0},
        {0, 2, 4, 0, 0, 0, 5, 3, 7},
        {2, 5, 0, 0, 4, 1, 0, 8, 0},
        {0, 0, 1, 0, 0, 8, 0, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 0},
        {3, 0, 0, 0, 7, 5, 0, 9, 1},
        {6, 0, 8, 0, 2, 0, 7, 0, 0},
        {7, 0, 0, 6, 9, 3, 8, 0, 0}};
    int combination2[9][9] = {
        {0, 0, 8, 0, 5, 0, 0, 0, 2},
        {0, 2, 0, 0, 9, 0, 0, 4, 1},
        {0, 0, 4, 0, 3, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 1, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 7, 0, 4, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 3},
        {0, 0, 7, 0, 6, 0, 4, 0, 0},
        {0, 6, 1, 3, 0, 0, 0, 9, 0}};

    if (decision_menu == 1)
    {
        game_check(combination0);
    }
    else if (decision_menu == 2)
    {
        game_check(combination1);
    }
    else if (decision_menu == 3)
    {
        game_check(combination2);
    }
}

int main()
{
    int decision_menu;
    system("cls");
    system("color 0D");
    printf("|=====================|\n");
    printf("|  Welcome to SUDOKU  |\n");
    printf("|=====================|\n");
    printf("|   1 - Easy Mode     |\n");
    printf("|   2 - Medium Mode   |\n");
    printf("|   3 - Hard Mode     |\n");
    printf("|=====================|\n");
    scanf("%d", &decision_menu);

    if (decision_menu == 1)
    {
        choose_matrix(decision_menu);
    }
    else if (decision_menu == 2)
    {
        choose_matrix(decision_menu);
    }
    else if (decision_menu == 3)
    {
        choose_matrix(decision_menu);
    }
    else
    {
        printf("Option not found. until later!!");
        Sleep(4000);
        main();
    }

    return 0;
}
