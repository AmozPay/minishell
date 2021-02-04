/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** exec_cmd
*/

#include "mysh.h"

int exec_cmdisfullpath(char *cmd, char **args, char **envarr, int *wstatus)
{
    pid_t pid = fork();

    if (pid == 0) {
        execve(cmd, args, envarr);
        exit(0);
    } else {
        wait(wstatus);
        return check_exitstatus(wstatus);
    }
}

void save_path_copy(char **cpy, char **path_env)
{
    if (*path_env != NULL) {
        *cpy = malloc(sizeof(char) * (my_strlen(*path_env) + 1));
        my_strcpy(*cpy, *path_env);
    } else
        *cpy = NULL;
}

int exec_cmd_cat(st_pathversions *pathver, int *wstatus)
{
    pid_t pid = fork();

    if (pid == 0) {
        execve(pathver->cmd_path, pathver->args, pathver->envarr);
        free(pathver->cmd_path);
        set_value("PATH", pathver->cpy, pathver->env);
        free(*(pathver->start));
        exit(0);
    } else {
        wait(wstatus);
        return check_exitstatus(wstatus);
    }
}

int exec_cmd_isntfullpath(st_pathversions *pathver, int *wstatus)
{
    save_path_copy(&(pathver->cpy), &(pathver->path_env));
    pathver->path = strtok(pathver->path_env, ":");
    pathver->cmd_path = cat_path(pathver->path, pathver->cmd);
    if (access(pathver->cmd_path, F_OK | X_OK) == 0) {
        return exec_cmd_cat(pathver, wstatus);
    }
    while ((pathver->path = strtok(NULL, ":")) != NULL) {
        pathver->path = strtok(NULL, ":");
        pathver->cmd_path = cat_path(pathver->path, pathver->cmd);
        if (access(pathver->cmd_path, F_OK | X_OK) == 0) {
            return exec_cmd_cat(pathver, wstatus);
        }
    }
    return -2;
}

int exec_cmdctl(char *cmd, char **args, st_env *env)
{
    st_pathversions pathver;
    int wstatus = 0;
    int err = 0;

    load_pathver(&pathver, args, env);
    if (access(cmd, F_OK | X_OK) == 0) {
        err = exec_cmdisfullpath(cmd, args, pathver.envarr, &wstatus);
        destroy_pathver(&pathver);
        return err;
    }
    err = exec_cmd_isntfullpath(&pathver, &wstatus);
    set_value("PATH", pathver.cpy, env);
    destroy_pathver(&pathver);
    if (err == -2) {
        my_puterr(cmd);
        my_puterr(": Command not found.\n");
        err = -1;
    }
    return err;
}