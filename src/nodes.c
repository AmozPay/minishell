/*
** EPITECH PROJECT, 2020
** my_nodes
** File description:
** nodes
*/

#include "nodes.h"
// replace "struct st_env" by the struct type you want
void push(struct st_env **env, struct st_env **new)
{
    if ((*env) != NULL) {
        (*env)->previous = *new;
        (*new) = (*new)->next;
        if (*new != NULL)
            (*new)->previous = NULL;
        (*env)->previous->next = *env;
        (*env) = (*env)->previous;
    } else {
        *env = *new;
        *new = (*new)->next;
        (*new)->previous = NULL;
        (*env)->next = NULL;
    }
}

struct st_env *pop_first(struct st_env **env)
{
    struct st_env *copy = *env;

    *env = (*env)->next;
    if (*env != NULL)
        (*env)->previous = NULL;
    copy->next = NULL;
    return copy;
}

void append(struct st_env **env, struct st_env **new)
{
    struct st_env *start = (*env);

    while ((*env)->next != NULL)
        *env = (*env)->next;
    (*new)->previous = *env;
    (*new)->next = NULL;
    (*env)->next = *new;
    (*env) = start;
}

struct st_env *pop_last(struct st_env **env)
{
    struct st_env *start = *env;
    struct st_env *last;

    while ((*env)->next != NULL)
        *env = (*env)->next;
    (*env)->previous->next = NULL;
    (*env)->previous = NULL;
    last = *env;
    *env = start;
    return last;
}