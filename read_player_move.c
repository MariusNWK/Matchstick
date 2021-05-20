/*
** EPITECH PROJECT, 2021
** read player move and update board
** File description:
** read the player move and update the board corresponding
*/

#include "include/my.h"

int read_player_move_and_update_board(char **board,
dimensions_t dimensions, int limit)
{
    int line = -1;
    int nb_matches = -1;

    my_putstr("Your turn:\n");
    while (line == -1 || nb_matches == -1) {
        line = handle_line(dimensions);
        if (line == -2)
            return (0);
        nb_matches = handle_nb_matches(line, board, limit);
        if (nb_matches == -2)
            return (0);
    }
    remove_msg("Player", nb_matches, line);
    delete_matches(board, line, nb_matches, dimensions);
    display_board(board);
    return (1);
}