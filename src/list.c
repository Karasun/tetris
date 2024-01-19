/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/


control_t *create_list(void)
{
    control_t *npl = malloc(sizeof(*npl));

    if (npl != NULL) {
        npl->begin = NULL;
        npl->end = NULL;
    }
    return (npl);
}

node_t *create_node(control_t *list, int nb)
{
    node_t *elem = malloc(sizeof(*elem));

    elem->nb = nb;

    if (!list->begin) {
        list->begin = elem;
        list->end = elem;
    } else
        elem->prev = list->end;
        list->end->next = elem;

    elem->next = NULL;
    list->end = elem;
}
