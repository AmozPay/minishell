/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** load_path
*/

#include "mysh.h"

void load_pathver(st_pathversions *pathver, char **args, st_env *env)
{
    pathver->cmd = *args;
    pathver->envarr = create_envarray(env);
    pathver->path_env = get_value("PATH", env);
    pathver->start = &(pathver->path_env);
    pathver->path = NULL;
    pathver->env = env;
    pathver->args = args;
}

void destroy_pathver(st_pathversions *pathver)
{
    for (int i = 0; pathver->envarr[i] != NULL; i++)
        free(pathver->envarr[i]);
    free(pathver->envarr);
}