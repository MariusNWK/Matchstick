/*
** EPITECH PROJECT, 2021
** display_board
** File description:
** display the board
*/

#include "include/my.h"

int is_a_stick_remaining(char **board)
{
    for (int i = 0; board[i]; i++)
        for (int j = 0; board[i][j] != '\0'; j++)
            if (board[i][j] == '|')
                return (1);
    return (0);
}

void display_board(char **board)
{
    for (int i = 0; board[i]; i++) {
        my_putstr(board[i]);
        my_putchar('\n');
    }
    if (is_a_stick_remaining(board))
        my_putchar('\n');
}