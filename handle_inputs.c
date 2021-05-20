/*
** EPITECH PROJECT, 2021
** handle_inputs
** File description:
** handle the inputs of the user
*/

#include "include/my.h"

int check_line(int line, int height)
{
    if (line <= 0 || line >= height - 1) {
        my_putstr("Error: this line is out of range\n");
        return (-1);
    }
    return (line);
}

int is_valid_nbr(char *input)
{
    for (int i = 0; input[i] != '\n'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return (0);
        }
    }
    return (1);
}

int check_matches(int line, int nb_matches, char **board, int limit)
{
    int count_matches = 0;
    if (nb_matches == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (nb_matches > limit) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(limit);
        my_putstr(" matches per turn\n");
        return (-1);
    }
    for (int i = 0; board[line][i] != '\0'; i++) {
        if (board[line][i] == '|')
            count_matches++;
    }
    if (nb_matches > count_matches) {
        my_putstr("Error: not enough matches on this line\n");
        return (-1);
    }
    return (nb_matches);
}

int handle_line(dimensions_t dimensions)
{
    char *input = NULL;
    size_t len = 0;
    int line = -1;

    do {
        my_putstr("Line: ");
        if (getline(&input, &len, stdin) == -1) {
            free(input);
            return (-2);
        }
        if (is_valid_nbr(input)) {
            line = my_getnbr(input);
            line = check_line(line, dimensions.height);
        }
        else {
            line = -1;
            my_putstr("Error: invalid input (positive number expected)\n");
        }
    } while (line == -1);
    free(input);
    return (line);
}

int handle_nb_matches(int line, char **board, int limit)
{
    char *input = NULL;
    size_t len = 0;
    int nb_matches = -1;

    my_putstr("Matches: ");
    if (getline(&input, &len, stdin) == -1) {
        free(input);
        return (-2);
    }
    if (is_valid_nbr(input)) {
        nb_matches = my_getnbr(input);
        nb_matches = check_matches(line, nb_matches, board, limit);
    }
    else
        my_putstr("Error: invalid input (positive number expected)\n");
    free(input);
    return (nb_matches);
}