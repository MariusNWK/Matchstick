/*
** EPITECH PROJECT, 2021
** remove msg
** File description:
** display the message when player or ai removed sticks
*/

#include "include/my.h"

void remove_msg(char const *user, int nb_matches, int line)
{
    my_putstr(user);
    my_putstr(" removed ");
    my_put_nbr(nb_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}