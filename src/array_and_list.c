/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** array_and_list
*/

#include "mysh.h"

st_env *create_node(char *input, st_env *prev)
{
    st_env *new = malloc(sizeof(st_env));
    char *value;

    new->value = NULL;
    new->next = NULL;
    new->previous = prev;
    new->var = my_strdup(strtok(input, "="));
    value = strtok(NULL, "");
    if (value != NULL) {
        new->value = malloc(sizeof(char) * (my_strlen(value) + 1));
        my_strcpy(new->value, value);
    }
    return new;
}

st_env *get_env(char **inputenv)
{
    st_env *first = NULL;
    st_env *new;
    st_env *prev = NULL;
    char *cwd = NULL;
    size_t size = 0;

    cwd = getcwd(cwd, size);
    while (*inputenv != NULL) {
        new = create_node(*inputenv, prev);
        if (prev == NULL)
            first = new;
        if (prev != NULL)
            prev->next = new;
        prev = new;
        inputenv++;
    }
    if (set_value("PWD", cwd, first) == -1)
        add_value("PWD", cwd, &first);
    return first;
}

static char *catenv(st_env *env)
{
    int lenvar = 0;
    int lenval = 0;
    char *str = NULL;
    char *cpy = NULL;

    if (env->var != NULL)
        lenvar = my_strlen(env->var);
    if (env->value != NULL)
        lenval = my_strlen(env->value);
    str = malloc(sizeof(char) * (lenvar + lenval + 2));
    cpy = str;
    my_strcpy(str, env->var);
    while (*str != '\0')
        str++;
    *str = '=';
    str++;
    if (env->value != NULL)
        my_strcpy(str, env->value);
    str = cpy;
    return str;
}

char **create_envarray(st_env *env)
{
    int cmpt = 0;
    st_env *first = env;
    char **envarr;
    int i = 0;

    while (env != NULL) {
        cmpt++;
        env = env->next;
    }
    env = first;
    envarr = malloc(sizeof(char *) * (cmpt + 1));
    while (i < cmpt) {
        envarr[i] = catenv(env);
        env = env->next;
        i++;
    }
    envarr[i] = NULL;
    env = first;
    return envarr;
}

void destroy_env(st_env *env)
{
    st_env *cpy;

    while (env != NULL) {
        cpy = env;
        env = env->next;
        if (cpy != NULL)
            free(cpy);
    }
}