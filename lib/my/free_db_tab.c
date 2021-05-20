/*
** EPITECH PROJECT, 2021
** free db tab
** File description:
** free a char **
*/

#include "../../include/my.h"

void free_db_tab(char **dbtab)
{
    char **tmp = dbtab;

    while (*dbtab) {
        free(*dbtab);
        dbtab++;
    }
    free(tmp);
}
