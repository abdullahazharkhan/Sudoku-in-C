#include <stdio.h>
#include <windows.h>
#include "functions.h"

int main()
{

    int decision_menu;
    system("cls");
    system("color 20");
    printf("\t\t|=====================|\n");
    Sleep(70);
    printf("\t\t|--Welcome to Sudoku--|\n");
    Sleep(70);
    printf("\t\t|=====================|\n");
    Sleep(70);
    printf("\t\t|   1 - Easy Mode     |\n");
    Sleep(20);
    printf("\t\t|   2 - Medium Mode   |\n");
    Sleep(20);
    printf("\t\t|   3 - Hard Mode     |\n");
    Sleep(20);
    printf("\t\t|=====================|\n");
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
