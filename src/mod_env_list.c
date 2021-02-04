/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** mod_env_list
*/

#include "mysh.h"

char *get_value(char *var, st_env *env)
{
    st_env *first = env;
    char *value;

    while (env != NULL) {
        if (my_strcmp(var, env->var) == 0) {
            value = env->value;
            env = first;
            return value;
        }
        env = env->next;
    }
    env = first;
    return NULL;
}

void opt_free(char *value)
{
    if (value != NULL)
        free(value);
}

int set_value(char *var, char *value, st_env *env)
{
    st_env *first = env;
    int err = -1;

    while (env != NULL) {
        if (my_strcmp(var, env->var) == 0) {
            opt_free(env->value);
            env->value = my_strdup(value);
            err = 0;
            break;
        }
        env = env->next;
    }
    env = first;
    return err;
}

void add_value(char *var, char *value, st_env **env)
{
    st_env *first = *env;
    st_env *new = malloc(sizeof(st_env));
    st_env *prev = NULL;

    new->var = my_strdup(var);
    if (value != NULL)
        new->value = my_strdup(value);
    else
        new->value = NULL;
    new->next = NULL;
    while (*env != NULL) {
        prev = *env;
        *env = (*env)->next;
    }
    if (prev != NULL) {
        prev->next = new;
        *env = first;
    }
    else
        *env = new;
}