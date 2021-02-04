/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** signal
*/

#include "mysh.h"

void handler(int num)
{
    num++;
    my_putchar('\n');
    return;
}

int check_exitstatus(int *wstatus)
{
    int exit_status = 0;

    if (WIFSIGNALED(*wstatus)) {
        my_putstr(strsignal(WTERMSIG(*wstatus)));
        if (WTERMSIG(*wstatus) == 11 && WCOREDUMP(*wstatus))
            my_puterr(" (core dumped)");
        my_puterr("\n");
    }
    if (!WIFEXITED(*wstatus))
        return -1;
    exit_status = WEXITSTATUS(*wstatus);
    if (exit_status != 0)
        return -1;
    return 0;
}