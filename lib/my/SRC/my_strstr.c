/*
** EPITECH PROJECT, 2020
** my strstr by Amoz PAY
** File description:
** finds a string in an other one, returns a pointer or null
*/

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int max_search_limit = my_strlen(str) - my_strlen(to_find);

    if (max_search_limit < 0)
        return ('\0');
    while (i + j <= max_search_limit) {
        while (str[i] != to_find[j] && i <= max_search_limit)
            i++;
        while (str[i + j] == to_find[j] && j < my_strlen(to_find) - 1)
            j++;
        if (str[i + j] == to_find[j])
            return (&str[i]);
        i++;
        j = 0;
    }
    return ('\0');
}
