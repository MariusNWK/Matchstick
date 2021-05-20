/*
** EPITECH PROJECT, 2021
** main
** File description:
** main matchstik
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return (84);
    return (matchstick(av));
}