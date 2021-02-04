/*
** EPITECH PROJECT, 2020
** my rev str by Amoz PAY
** File description:
** reverses a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int a = 0;
    int z = 0;
    char buffer_a = 0;
    char buffer_z = 0;

    z = my_strlen(str) - 1;
    while (z > a) {
        buffer_a = str[a];
        buffer_z = str[z];
        str[a] = buffer_z;
        str[z] = buffer_a;
        a++;
        z--;
    }
    return (str);
}
