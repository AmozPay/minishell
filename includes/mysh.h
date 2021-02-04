/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_
////////////////////////////////
////////// INCLUDES ////////////
////////////////////////////////
#include "my.h"
#include "nodes.h"
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

////////////////////////////////
/////// GLOBAL VARIABLES ///////
////////////////////////////////


////////////////////////////////
//////////// MACROS ////////////
////////////////////////////////
#define PROMPT "\e[1m\e[32m➜  \e[0m\e[1m\e[36m"
#define ERR_PROMPT "\e[1m\e[31m➜  \e[0m\e[1m\e[36m"
#define RESET_ATTRIBUTES "\e[39m\e[0m "

////////////////////////////////
////////// STRUCTURES //////////
////////////////////////////////

typedef struct st_pathversions {
    char *cpy;
    char *path;
    char *path_env;
    char **start;
    char *cmd;
    char *cmd_path;
    char **args;
    char **envarr;
    st_env *env;
} st_pathversions;

enum sh_cmd {
    cd_cmd,
    env_cmd,
    setenv_cmd,
    unsetenv_cmd,
    exit_cmd,
    none
};

////////////////////////////////
////////// PROTOTYPES  /////////
////////////////////////////////

//////////// main.c ////////////
char *cat_path(char *path, char *cmd);

//////// clean_str.c ///////////
void clean_str(char *str);

/////// arrays_and_list.c //////
st_env *get_env(char **inputenv);
char **create_envarray(st_env *env);
void destroy_env(st_env *env);

/////// line_parsing.c /////////
char **parse_line(char *line);
void reset_line(char **line, size_t *n);
char *cat_path(char *path, char *cmd);

////// mod_env_list.c //////////
char *get_value(char *var, st_env *env);
int set_value(char *var, char *value, st_env *env);
void add_value(char *var, char *value, st_env **env);

////////// exec_cmd.c ///////////
int exec_cmdctl(char *cmd, char **args, st_env *env);

//////// load_path.c ////////////
void load_pathver(st_pathversions *pathver, char **args, st_env *env);
void destroy_pathver(st_pathversions *pathver);

//////// sh_commands.c //////////
int shell_command(char **cmd, st_env **env);
int get_nbargs(char **args);

/////// disp_env.c //////////////
int disp_env(char **args, st_env *env);

/////////// cd_cmd.c ////////////
int cd_ctl(char **args, st_env *env);
char *my_strdup(char *str);

////////// setenv.c /////////////
int setenv_ctl(char **args, st_env *env);

///////// unsetenv.c ////////////
int unsetenv_ctl(char **args, st_env **env);

////////// signal.c /////////////
void handler(int num);
int check_exitstatus(int *wstatus);

//////// prompt.c ///////////////
void prompt(int err, st_env *env);

//////// cd_permissions.c ///////
int check_isdir(char *path, char *relpath);
int check_permission(char *fullpath, char *relpath);

#endif /* !MYSH_H_ */