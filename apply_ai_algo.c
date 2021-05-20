/*
** EPITECH PROJECT, 2021
** apply ai algo and update board
** File description:
** apply the ia algo and update the board
*/

#include "include/my.h"

int count_line_sticks_nbr(char *line)
{
    int sticks_nbr = 0;

    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] == '|') {
            sticks_nbr++;
        }
    }
    return (sticks_nbr);
}

list_t *define_lines(char **board, dimensions_t dim)
{
    list_t *library = NULL;
    infos_t info = {-1, -1};
    int sticks_nbr = 0;

    for (int i = 1; i < dim.height - 1; i++) {
        sticks_nbr = count_line_sticks_nbr(board[i]);
        if (sticks_nbr > 0) {
            library = add_at(library, (infos_t){i, sticks_nbr}, 0);
        }
    }
    return (library);
}

int find_nb_matches_to_remove(char **board, dimensions_t dim, int limit)
{
    int sticks_nbr = count_sticks_nbr(board, dim.width, dim.height);
    int losing_position = 0;
    int k = 0;

    for (int i = 0; sticks_nbr > losing_position; i++) {
        losing_position = i * limit + (i + 1);
        if (sticks_nbr > losing_position)
            k = i;
    }
    losing_position = k * limit + (k + 1);
    return (sticks_nbr - losing_position);
}

int find_line_to_remove_matches(list_t *library, int *nb_matches)
{
    infos_t info = {0, 0};
    int len = len_list(library);
    int max_sticks_nbr = 0;
    int line_max_sticks_nbr = 0;

    for (int i = 0; i < len; i++) {
        info = get_at(library, i);
        if (info.sticks_nbr == *nb_matches)
            return (info.line);
    }
    for (int i = 0; i < len; i++) {
        info = get_at(library, i);
        if (info.sticks_nbr > max_sticks_nbr) {
            max_sticks_nbr = info.sticks_nbr;
            line_max_sticks_nbr = info.line;
        }
    }
    if (*nb_matches > max_sticks_nbr)
        *nb_matches = max_sticks_nbr;
    return (line_max_sticks_nbr);
}

void apply_ai_algo_and_update_board(char **board, dimensions_t dim, int limit)
{
    list_t *library = define_lines(board, dim);
    int nb_matches = 0;
    int line = 0;

    limit = define_limit(library, limit);
    nb_matches = find_nb_matches_to_remove(board, dim, limit);
    if (nb_matches == 0)
        nb_matches = 1;
    if (nb_matches > limit)
        nb_matches = 1;
    line = find_line_to_remove_matches(library, &nb_matches);
    my_putstr("AI's turn...\n");
    remove_msg("AI", nb_matches, line);
    delete_matches(board, line, nb_matches, dim);
    free_list(library);
    display_board(board);
}