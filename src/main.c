/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "../inc/my.h"

control_t *add_node(control_t *list, int nb)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->nb = nb;

    if (list == NULL) {
        list = malloc(sizeof(control_t));
        list->begin = new_node;
        list->end = new_node;
    } else {
        new_node->prev = l_a->end;
        list->end->next = new_node;
        list->end = new_node;
    }
    return (list);
}
void read_list(control_t *list)
{
    node_t *tmp = list->begin;
    while (tmp != NULL) {
        printf("%d", tmp->nb);
        tmp = tmp->next;
        if (tmp != NULL) {
            printf("%s", "->");
        }
    }
}

int main(int ac, char **av)
{
    control_t *list;
    //list = create_list();
    int i = 1;

    if (ac < 1)
        return (84);
    while (av[i] != NULL) {
        list = add_node(list, my_getnbr(av[i]));
        i++;
    }
    read_list(list);
    return (0);
}
