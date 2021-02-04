/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** unsetenv
*/

#include "mysh.h"

void my_unsetenv(char *var, st_env **env)
{
    st_env *stack = NULL;
    st_env *to_be_erased = NULL;

    while (*env != NULL && my_strcmp(var, (*env)->var)) {
        push(&stack, env);
    }
    if (*env != NULL)
        to_be_erased = pop_first(env);
    while (stack != NULL)
        push(env, &stack);
    if (to_be_erased != NULL) {
        free(to_be_erased->var);
        free(to_be_erased->value);
        free(to_be_erased);
    }
}

int unsetenv_ctl(char **args, st_env **env)
{
    int nb_args = get_nbargs(args);

    if (nb_args < 2) {
        my_puterr("unsetenv: Too few arguments.\n");
        return -1;
    }
    for (int i = 1; i < nb_args; i++) {
        my_unsetenv(args[i], env);
    }
    return 0;
}