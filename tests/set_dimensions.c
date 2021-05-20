/*
** EPITECH PROJECT, 2021
** set_dimensions
** File description:
** set the width and the height of the board
*/

#include "include/my.h"

dimensions_t set_dimensions(int size)
{
    dimensions_t dimensions = {size * 2 + 1, size + 2};

    return (dimensions);
}