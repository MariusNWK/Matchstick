/*
** EPITECH PROJECT, 2020
** list2
** File description:
** pushswap
*/

#include "../../include/my.h"

infos_t get_at(list_t *list, int pos)
{
    int i = 0;

    if (is_empty_list(list)) {
        return ((infos_t){-1, -1});
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    return (list->data);
}

void set_at(list_t *list, infos_t data, int pos)
{
    int i = 0;

    if (is_empty_list(list)) {
        return;
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    list->data = data;
}

list_t *free_at(list_t *list, int pos)
{
    list_t *prec = list;
    list_t *cur = list;
    int i = 0;

    if (is_empty_list(list)) {
        return (NULL);
    }
    if (pos == 0) {
        list = list->next;
        free(cur);
        return (list);
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cur->next;
    free(cur);
    return (list);
}

list_t *free_list(list_t *list)
{
    list_t *tmp = NULL;

    while (list) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return (list);
}