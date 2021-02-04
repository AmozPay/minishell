/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** setenv
*/

#include "mysh.h"

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int setenv_null(char **args, st_env *env)
{
    if (!is_alpha(args[1][0])) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    if (set_value(args[1], NULL, env) == -1)
        add_value(args[1], NULL, &env);
    return 0;
}

int setenv_value(char **args, st_env *env)
{
    if (!is_alpha(args[1][0])) {
        my_puterr("setenv: Variable name must begin with a letter.\n");
        return -1;
    }
    if (set_value(args[1], args[2], env) == -1)
        add_value(args[1], args[2], &env);
    return 0;
}

int setenv_ctl(char **args, st_env *env)
{
    int nb_args = get_nbargs(args);

    switch (nb_args) {
    case 1:
        return disp_env(args, env);
    case 2:
        return setenv_null(args, env);
     case 3:
        return setenv_value(args, env);
    default:
        my_puterr("setenv: Too many arguments.\n");
        return -1;
    }
}