/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** sh_commands
*/

#include "mysh.h"

int find_shcmd(char *command_names[5], char *cmd)
{
    for (int i = 0; i < 5; i++) {
        if (my_strcmp(cmd, command_names[i]) == 0) {
            return i;
        }
    }
    return none;
}

int get_nbargs(char **args)
{
    int nb_args = 0;

    for (int i = 0; args[i] != NULL; i++)
        nb_args++;
    return nb_args;
}

int exit_ctl(char **args)
{
    int nb_args = get_nbargs(args);

    if (nb_args == 1)
        exit(0);
    my_puterr("exit: Expression Syntax.\n");
    return -1;
}

int shell_command(char **args, st_env **env)
{
    char *command_names[5] = {"cd", "env", "setenv", "unsetenv", "exit"};
    enum sh_cmd sh_cmd = find_shcmd(command_names, args[0]);

    switch (sh_cmd) {
    case cd_cmd:
        return cd_ctl(args, *env);
    case env_cmd:
        return disp_env(args, *env);
    case setenv_cmd:
        return setenv_ctl(args, *env);
    case unsetenv_cmd:
        return unsetenv_ctl(args, env);
    case exit_cmd:
        return exit_ctl(args);
    default:
        return -2;
    }
}