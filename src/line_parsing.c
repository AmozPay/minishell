/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** line_parsing
*/

#include "mysh.h"

static void jump_arg(char *line, int *i)
{
    while (line[*i] != '\0' && line[*i] != ' ')
        (*i)++;
    if (line[*i] == ' ')
        (*i)++;
}

static int count_args(char *line)
{
    int cmpt = 0;
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] != ' ') {
            cmpt++;
            jump_arg(line, &i);
        }
    }
    return cmpt;
}

char **parse_line(char *line)
{
    int nb_args = count_args(line);
    char **array2d;
    int i = 1;

    if (nb_args > 0) {
        array2d = malloc(sizeof(char *) * (nb_args + 1));
        array2d[0] = strtok(line, " ");
        while (i < nb_args) {
            array2d[i] = strtok(NULL, " ");
            i++;
        }
        array2d[i] = NULL;
        return array2d;
    }
    return NULL;
}

void get_len(char *path, int *pathlen, char *cmd, int *cmdlen)
{
    *pathlen = my_strlen(path);
    *cmdlen = my_strlen(cmd);
}

char *cat_path(char *path, char *cmd)
{
    int pathlen = 0;
    int cmdlen = 0;
    char *cat;
    int i = 0;

    if (path == NULL)
        return cmd;
    if (cmd == NULL)
        return path;
    get_len(path, &pathlen, cmd, &cmdlen);
    if (pathlen > 0 && path[pathlen - 1] == '/')
        return (my_strcat(path, cmd));
    cat = malloc(sizeof(char) * (pathlen + cmdlen + 2));
    my_strcpy(cat, path);
    while (cat[i] != '\0')
        i++;
    cat[i] = '/';
    i++;
    my_strcpy(cat + i, cmd);
    return cat;
}