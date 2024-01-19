/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

void    find_file(char *av)
{
    DIR *elem = opendir("./");
    struct dirent *sd;
    struct stat fs;

    if (elem == NULL)
        exit (84);
    while ((sd=readdir(elem)) != NULL) {
        if (av[0] == '-' && av[1] == 'l')
            all_right(fs);
        else if (sd->d_name[0] != '.') {
            my_putstr(sd->d_name);
            my_putstr("  ");
        }
    }
    my_putchar('\n');
    closedir(elem);
}
