/*
** EPITECH PROJECT, 2021
** count sticks nbr
** File description:
** counter the number of sticks
*/

#include "include/my.h"

int is_a_stick(char c, int sticks_nbr)
{
    if (c == '|') {
        sticks_nbr += 1;
    }
    return (sticks_nbr);
}

int count_sticks_nbr(char **board, int width, int height)
{
    int sticks_nbr = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sticks_nbr = is_a_stick(board[i][j], sticks_nbr);
        }
    }
    return (sticks_nbr);
}