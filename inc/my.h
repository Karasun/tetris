/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/


#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node_s
{
    struct node_s *next;
    struct node_s *prev;
    char *name;
    char *size;
    int color;
}node_t;

typedef struct control_s
{
    node_t *begin;
    node_t *end;
}control_t;

control_t *add_node(control_t *list, int nb);
void read_list(control_t *list);
int main(int ac, char **av);

#endif

//ex struct
/*
typedef struct obj_s
{
	char *name;
	vector_s *size;
	int color;
	char **tetrimino;
	struct obj_s *next;
	struct obj_s *prev;
} obj_s;
*/
