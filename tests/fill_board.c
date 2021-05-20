/*
** EPITECH PROJECT, 2021
** fill board
** File description:
** fill the board with the number of matchsticks corresponding to the size
*/

#include "include/my.h"

char **define_char(int i, int j, dimensions_t dimensions, char **board)
{
    if (i == 0 || i == dimensions.height - 1 ||
        j == 0 || j == dimensions.width - 1) {
        board[i][j] = '*';
    }
    else if (i >= 1 && j >= (dimensions.height - 2) - (i - 1) &&
        j <= (dimensions.height - 2) + (i - 1))
        board[i][j] = '|';
    else
        board[i][j] = ' ';
    return (board);
}

char **fill_board(dimensions_t dimensions)
{
    char **board = malloc(sizeof(char *) * (dimensions.height + 1));

    for (int i = 0; i < dimensions.height; i++) {
        board[i] = malloc(sizeof(char) * (dimensions.width + 1));
        for (int j = 0; j < dimensions.width; j++) {
            board = define_char(i, j, dimensions, board);
        }
        board[i][dimensions.width] = '\0';
    }
    board[dimensions.height] = NULL;
    return (board);
}