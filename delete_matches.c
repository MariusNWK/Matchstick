/*
** EPITECH PROJECT, 2021
** update board
** File description:
** delete matchsticks from the board
*/

#include "include/my.h"

void delete_matches(char **board, int line,
int nb_matches, dimensions_t dimensions)
{
    for (int i = dimensions.width - 1; i >= 0 && nb_matches > 0; i--) {
        if (board[line][i] == '|') {
            board[line][i] = ' ';
            nb_matches--;
        }
    }
}