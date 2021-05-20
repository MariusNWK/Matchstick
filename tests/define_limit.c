/*
** EPITECH PROJECT, 2021
** define limit
** File description:
** change limit if max sticks nbr a line is inferior than limit
*/

#include "include/my.h"

int define_limit(list_t *library, int limit)
{
    int len = len_list(library);
    infos_t info;
    int max_sticks_nbr = 0;

    for (int i = 0; i < len; i++) {
        info = get_at(library, i);
        if (info.sticks_nbr > max_sticks_nbr)
            max_sticks_nbr = info.sticks_nbr;
    }
    if (max_sticks_nbr < limit)
        limit = max_sticks_nbr;
    return (limit);
}