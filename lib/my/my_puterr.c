/*
** EPITECH PROJECT, 2021
** my_puterr
** File description:
** display on error output
*/

#include <unistd.h>
#include "../../include/my.h"

void my_puterr(char const *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}
