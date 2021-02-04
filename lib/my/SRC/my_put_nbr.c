/*
** EPITECH PROJECT, 2020
** my_put_nbr By Amoz PAY
** File description:
** displays a number
*/

void my_putchar(char c);

long my_put_nbr(long nb)
{
    long long nb_long_long = nb;

    if (nb_long_long < 0) {
        my_putchar('-');
        nb_long_long = nb_long_long * (-1);
    }
    if (nb_long_long < 10) {
        my_putchar(nb_long_long + 48);
    } else {
        my_put_nbr(nb_long_long / 10);
        my_put_nbr(nb_long_long % 10);
    }
    return (0);
}

unsigned long my_put_u_nbr(unsigned long nb)
{
    if (nb < 10) {
        my_putchar(nb + 48);
    } else {
        my_put_u_nbr(nb / 10);
        my_put_u_nbr(nb % 10);
    }
    return (0);
}
