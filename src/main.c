/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** main
*/

#include "mysh.h"

char **get_cmd(char **line, size_t *n)
{
    char **cmd;

    if (getline(line, n, stdin) == -1) {
        if (isatty(0))
            my_putstr("exit\n");
        exit(0);
    }
    clean_str(*line);
    cmd = parse_line(*line);
    return cmd;
}

void reset_cmd(char **cmd, char **line, size_t *n)
{
    free(*line);
    *line = NULL;
    *n = 0;
    free(cmd);
}

int cmd_ctl(char *cmd, char **args, st_env **env)
{
    int err = -2;

    err = shell_command(args, env);
    if (err == -2)
        err = exec_cmdctl(cmd, args, *env);
    return err;
}

void mysh(char **inputenv)
{
    st_env *env = get_env(inputenv);
    char *line = NULL;
    char **cmd;
    int err = 0;
    size_t n = 0;

    while (1) {
        signal(SIGINT, handler);
        if (isatty(0))
            prompt(err, env);
        cmd = get_cmd(&line, &n);
        if (cmd != NULL)
            err = cmd_ctl(*cmd, cmd, &env);
        else
            err = 0;
        reset_cmd(cmd, &line, &n);
    }
    destroy_env(env);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1) {
        my_puterr("Usage: ./mysh\n");
        return 84;
    } else {
        mysh(env);
        return 0;
    }
}