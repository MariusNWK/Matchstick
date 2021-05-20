/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** Return 84 in case of error.
*/

#include "include/my.h"

int are_only_figures(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (0);
        }
    }
    return (1);
}

int error_case(char const *str)
{
    my_puterr(str);
    return (84);
}

int error_handling(int ac, char **av)
{
    int arg1 = 0;
    int arg2 = 0;

    if (ac != 3)
        return (error_case("Invalid number of arguments\n"));
    if (are_only_figures(av[1]) == 0 || are_only_figures(av[2]) == 0)
        return (error_case("Arguments must be integer numbers\n"));
    arg1 = my_getnbr(av[1]);
    arg2 = my_getnbr(av[2]);
    if (arg1 <= 1 || arg1 >= 100)
        return (error_case("Number of lines must be between 1 and 100\n"));
    if (arg2 < 1)
        return (error_case("The maximum number of mathch(es) must be > 0\n"));
    return (0);
}