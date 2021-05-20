/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task 2
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int my_putstr(char const *);
void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
void my_puterr(char const *);
void free_db_tab(char **);

///////////////////////////////////////////////////

typedef struct Infos {
    int line;
    int sticks_nbr;
} infos_t;

typedef struct Cell
{
    infos_t data;
    struct Cell *next;
} list_t, cell_t;

int is_empty_list(list_t *);
long len_list(list_t *);
list_t *add_at(list_t *, infos_t, int);
infos_t get_at(list_t *, int);
void set_at(list_t *, infos_t, int);
list_t *free_at(list_t *, int);
list_t *free_list(list_t *);

///////////////////////////////////////////////////

typedef struct Dimensions
{
    int width;
    int height;
} dimensions_t;

///////////////////////////////////////////////////

int error_handling(int, char **);

///////////////////////////////////////////////////

char **fill_board(dimensions_t);

///////////////////////////////////////////////////

void display_board(char **);

///////////////////////////////////////////////////

void delete_matches(char **, int, int, dimensions_t);

///////////////////////////////////////////////////

dimensions_t set_dimensions(int);

///////////////////////////////////////////////////

int read_player_move_and_update_board(char **, dimensions_t, int);

///////////////////////////////////////////////////

int handle_line(dimensions_t);
int handle_nb_matches(int, char **, int);

///////////////////////////////////////////////////

int count_sticks_nbr(char **, int, int);

///////////////////////////////////////////////////

int matchstick(char **);

///////////////////////////////////////////////////

void apply_ai_algo_and_update_board(char **, dimensions_t, int, int);

///////////////////////////////////////////////////

void remove_msg(char const *, int, int);

///////////////////////////////////////////////////

int define_limit(list_t *, int);

///////////////////////////////////////////////////

///////////////////////////////////////////////////

///////////////////////////////////////////////////

///////////////////////////////////////////////////

///////////////////////////////////////////////////