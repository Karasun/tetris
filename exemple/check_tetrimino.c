/*
** EPITECH PROJECT, 2018
** check_tetrimino
** File description:
** header
*/

#include "tetris.h"

int	check_line(char *params)
{
	int count = 0;

	if (my_strlen(params) < 5)
		return (1);
	for (int pos = 0; params[pos]; pos++) {
		if ((params[pos] > '9' || params[pos] < '0') &&
		params[pos] != ' ')
			return (2);
		if (params[pos] == ' ')
			count++;
		if (count > 2)
			return (3);
	}
	return (0);
}

void add_val(int arg, obj_s *tetrimino, int val)
{
	if ((arg == 2 && val > 7) || (arg != 2 && val == 0))
		exit(84);
	if (arg == 0)
		tetrimino->size->x = val;
	else if (arg == 1)
		tetrimino->size->y = val;
	else
		tetrimino->color = val;
}

int	check_arg_params(char *params, int arg, obj_s *tetrimino)
{
	int pos = 0;
	int val = arg;
	char buffer[20];

	for (; val > 0; pos++) {
		if (pos > my_strlen(params))
			return (84);
		if (params[pos] == ' ')
			val--;
	}
	for (; params[pos] != 0; pos++) {
		if (params[pos] == ' ')
			break;
		buffer[val] = params[pos];
		buffer[val + 1] = 0;
		val++;
	}
	val = my_getnbr(buffer);
	add_val(arg, tetrimino, val);
	return (0);
}

int	check_real_tetrimino(char **tetri, vector_s *size)
{
	int prem_x = 10;
	int der_x = 0;
	int max_x = 0;
	int pos_col = 0;
	int pos_line = 0;
	int star = 0;

	for (; tetri[pos_line]; pos_col++) {
		if (tetri[pos_line][pos_col] == '*') {
			star++;
			if (pos_col < prem_x)
				prem_x = pos_col;
			if (pos_col > der_x)
				der_x = pos_col;
		}
		if (tetri[pos_line][pos_col] == 0) {
			if (star == 0)
				return (1);
			star = 0;
			pos_line++;
			pos_col = -1;
		}
	}
	max_x = der_x - prem_x + 1;
	if (pos_line != size->y || max_x != size->x)
		return (2);
	return (0);
}

void	compare_map_tetri(list_obj_s *list, commands_s *command)
{
	obj_s *tmp = list->first;

	for (; tmp != NULL; tmp = tmp->next) {
		if (tmp->size->x > command->size->x)
			tmp->size->x = -1;
		if (tmp->size->y > command->size->y)
			tmp->size->x = -1;
	}
}
