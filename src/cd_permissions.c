/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-minishell1-amoz.pay
** File description:
** cd_permission
*/

#include "mysh.h"

int check_isdir(char *path, char *relpath)
{
    struct stat statbuf;
    int result = stat(path, &statbuf);

    if (result == -1) {
        if (relpath != NULL)
            my_puterr(relpath);
        else
            my_puterr(path); 
        my_puterr(": No such file or directory.\n");
        return -1;
    }
    if (!S_ISDIR(statbuf.st_mode)) {
        if (relpath != NULL)
            my_puterr(relpath);
        else
            my_putstr(path);
        my_putstr(": Not a directory.\n");
        return -1;
    }
    return 0;
}

int check_permission(char *fullpath, char *relpath)
{
    if (access(fullpath, R_OK) == -1) {
        if (relpath != NULL)
            my_puterr(relpath);
        else
            my_puterr(fullpath);
        my_puterr(": Permission denied.\n");
        return -1;
    }
    return 0;
}