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

int matchstick(char **av)
{
    char **board;
    dimensions_t dim;
    int limit = 0;

    dim = set_dimensions(my_getnbr(av[1]));
    board = fill_board(dim);
    display_board(board);
    limit = my_getnbr(av[2]);
    while (1) {
        if (read_player_move_and_update_board(board, dim, limit) == 0)
            return (exit_game(0, "", board));
        if (count_sticks_nbr(board, dim.width, dim.height) == 0)
            return (exit_game(2, "You lost, too bad...\n", board));
        apply_ai_algo_and_update_board(board, dim, limit);
        if (count_sticks_nbr(board, dim.width, dim.height) == 0)
            return (exit_game(1,
            "I lost... snif... but I'll get you next time!!\n", board));
    }
    return (0);
}