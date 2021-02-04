/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** prompt
*/

#include "mysh.h"

void prompt_cwd(char *cwd)
{
    int len = my_strlen(cwd);
    int start = 0;

    start = len - 1;
    for (int i = len - 1; cwd[i] != '/'; i--)
        start--;
    if (cwd[start] == '/')
        start++;
    if (cwd[len - 1] == '/')
        start = 0;
    my_putstr(cwd + start);
    my_putstr(RESET_ATTRIBUTES);
    free(cwd);
}

void prompt_selec(st_env *env)
{
    char *buff = NULL;
    char *home = get_value("HOME", env);

    buff = getcwd(buff, (size_t)0);
    if (home != NULL && !my_strcmp(home, buff)) {
        my_putstr("~");
        my_putstr(RESET_ATTRIBUTES);
        free(buff);
    } else
        prompt_cwd(buff);
}

void prompt(int err, st_env *env)
{
    if (err == 0)
        my_putstr(PROMPT);
    else
        my_putstr(ERR_PROMPT);
    prompt_selec(env);
}