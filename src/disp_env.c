/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** disp_env
*/

#include "mysh.h"

int disp_env(char **args, st_env *env)
{
    int nb_args = get_nbargs(args);
    st_env *start = env;

    if (nb_args != 1) {
        my_puterr("env: '");
        my_puterr(args[1]);
        my_puterr("': No such file or directory\n");
        return -1;
    }
    while (env != NULL) {
        if (env->var != NULL)
            my_putstr(env->var);
        my_putchar('=');
        if (env->value != NULL)
            my_putstr(env->value);
        my_putchar('\n');
        env = env->next;
    }
    env = start;
    return 0;
}