#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "functions.h"

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
