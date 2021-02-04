/*
** EPITECH PROJECT, 2020
** my_nodes
** File description:
** nodes
*/

#ifndef NODES_H_
#define NODES_H_

////////////////////////////////
////////// INCLUDES ////////////
////////////////////////////////
#include <stddef.h>

////////////////////////////////
/////// GLOBAL VARIABLES ///////
////////////////////////////////


////////////////////////////////
//////////// MACROS ////////////
////////////////////////////////


////////////////////////////////
////////// STRUCTURES //////////
////////////////////////////////

// REPLACE BY ADEQUATE STRUCTURE
typedef struct st_env {
    struct st_env *previous;
    struct st_env *next;
    char *var;
    char *value;
} st_env;

////////////////////////////////
////////// PROTOTYPES  /////////
////////////////////////////////
void push(struct st_env **env,struct st_env **new);
struct st_env *pop_first(struct st_env **env);
void append(struct st_env **env, struct st_env **new);
struct st_env *pop_last(struct st_env **env);
struct st_env *pop_index(struct st_env **env, int index);

#endif /* !NODES_H_ */