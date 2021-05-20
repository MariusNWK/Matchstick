/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** main function of matchstick
*/

#include "include/my.h"

int exit_game(int return_value, char const *msg, char **board)
{
    free_db_tab(board);
    my_putstr(msg);
    return (return_value);
}

void who_must_win(char **board, dimensions_t dim, int limit)
{
    int sticks_nbr = count_sticks_nbr(board, dim.width, dim.height);
    int losing_position = 0;
    int k = 0;

    for (int i = 0; sticks_nbr > losing_position; i++) {
        losing_position = i * limit + (i + 1);
    }
    if (losing_position == sticks_nbr) {
        my_putstr("P2 must win   ");
    }
    else {
        my_putstr("P1 must win   ");
    }
}

int matchstick(char **av)
{
    char **board;
    dimensions_t dim;
    int limit = 0;

    dim = set_dimensions(my_getnbr(av[1]));
    board = fill_board(dim);
    // display_board(board);
    limit = my_getnbr(av[2]);
    who_must_win(board, dim, limit);
    while (1) {
        apply_ai_algo_and_update_board(board, dim, limit, 1);
        if (count_sticks_nbr(board, dim.width, dim.height) == 0)
            return (exit_game(2, "Player 2 won\n", board));
        apply_ai_algo_and_update_board(board, dim, limit, 2);
        if (count_sticks_nbr(board, dim.width, dim.height) == 0)
            return (exit_game(1, "Player 1 won\n", board));
    }
    return (0);
}