/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** cd_cmd
*/

#include "mysh.h"

char *my_strdup(char *str)
{
    int len = 0;
    char *new;

    if (str != NULL) {
        len = my_strlen(str);
        new = malloc(sizeof(char) * (len + 1));
        my_strcpy(new, str);
        return new;
    }
    return NULL;
}

int cd_home(st_env *env)
{
    char *old_pwd = get_value("PWD", env);
    char *new_pwd = NULL;
    size_t size = 0;
    char *home = get_value("HOME", env);

    if (home == NULL) {
        my_puterr("cd: No home directory.\n");
        return -1;
    }
    old_pwd = my_strdup(old_pwd);
    if (set_value("OLDPWD", old_pwd, env) == -1)
        add_value("OLDPWD", old_pwd, &env);
    if (!chdir(home)) {
        new_pwd = getcwd(new_pwd, size);
        set_value("PWD", new_pwd, env);
    }
    return 0;
}

int cd_fullpath(char *fullpath, char *relpath, st_env *env)
{
    char *old_pwd = get_value("PWD", env);
    char *new_pwd = NULL;
    size_t size = 0;

    if (check_isdir(fullpath, relpath) == -1)
        return -1;
    if (check_permission(fullpath, relpath) == -1)
        return -1;
    old_pwd = my_strdup(old_pwd);
    if (!chdir(fullpath)) {
        if (set_value("OLDPWD", old_pwd, env) == -1)
            add_value("OLDPWD", old_pwd, &env);
        new_pwd = getcwd(new_pwd, size);
        set_value("PWD", new_pwd, env);
        return 0;
    }
    free(old_pwd);
    return -1;
}

int cd_relpath(char *relpath, st_env *env)
{
    char *cwd = my_strdup(get_value("PWD", env));
    char *fullpath = my_strcat(cwd, "/");

    free(cwd);
    cwd = fullpath;
    fullpath = my_strcat(cwd, relpath);
    free(cwd);
    return cd_fullpath(fullpath, relpath, env);
}

int cd_ctl(char **args, st_env *env)
{
    int nb_args = get_nbargs(args);

    if (nb_args > 2) {
        my_puterr("cd: Too many arguments.\n");
        return -1;
    }
    if (nb_args == 1 || (nb_args == 2 && !my_strcmp(args[1], "~")))
        return cd_home(env);
    if (args[1][0] == '/')
        return cd_fullpath(args[1], NULL, env);
    if (args[1][0] == '-')
        return cd_fullpath(get_value("OLDPWD", env), NULL, env);
    return cd_relpath(args[1], env);
    return 0;
}