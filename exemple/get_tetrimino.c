/*
** EPITECH PROJECT, 2018
** get_tetrimino
** File description:
** header
*/

#include "tetris.h"

int	get_tetri_params(obj_s *tetrimino, char *params)
{
	if (params[0] == 0)
		return (5);
	if (check_line(params) != 0)
		return (4);
	if (check_arg_params(params, 0, tetrimino) != 0)
		return (1);
	if (check_arg_params(params, 1, tetrimino) != 0)
		return (2);
	if (check_arg_params(params, 2, tetrimino) != 0)
		return (3);
	return (0);
}

void	get_real_tetrimino(obj_s *tetrimino, int fd)
{
	char *str;
	int count = 0;
	char **tab;

	tab = malloc(sizeof(char *) * (tetrimino->size->y + 1));
	for (str = get_next_line(fd); str; count++) {
		tab[count] = str;
		str = get_next_line(fd);
	}
	tab[count] = 0;
	tetrimino->tetrimino = tab;
}

char	*get_params(int fd)
{
	char buffer[20];
	char *str = malloc(20);
	int count = 0;

	buffer[count] = 0;
	for (; read(fd, buffer + count, 1) != -1; count++) {
		if (buffer[count] == 0 || count > 19)
			break;
		if (buffer[count] == '\n')
			break;
	}
	buffer[count] = 0;
	for (count = 0; buffer[count]; count++)
		str[count] = buffer[count];
	str[count] = 0;
	return (str);
}

void	get_tetrimino(char *path, list_obj_s *list, struct dirent *file)
{
	obj_s *tetrimino = init_tetrimino(list);
	int fd = open_file(path, file->d_name);
	char *name = malloc(my_strlen(file->d_name) + 1);
	char *params = get_params(fd);

	for (int count = 0; file->d_name[count] != '.'; count++) {
		name[count] = file->d_name[count];
		name[count + 1] = 0;
	}
	tetrimino->name = name;
	if (get_tetri_params(tetrimino, params) != 0)
		tetrimino->size->x = -1;
	else {
		get_real_tetrimino(tetrimino, fd);
		if (check_real_tetrimino(tetrimino->tetrimino,
			tetrimino->size) != 0)
			tetrimino->size->x = -1;
	}
	free(params);
	close(fd);
}

list_obj_s *get_tetrimino_list(void)
{
	list_obj_s *list = init_list();
	struct dirent *file = NULL;
	char path[] = "./tetriminos/";
	DIR *dir = opendir(path);

	if (dir == NULL)
		exit(84);
	file = readdir(dir);
	while (file != NULL) {
		if (my_strcmp(file->d_name, ".") == 1 &&
			my_strcmp(file->d_name, "..") == 1)
			if (verif_ext(file->d_name) == 1)
				get_tetrimino(path, list, file);
		file = readdir(dir);
	}
	closedir(dir);
	return (list);
}
