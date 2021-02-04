/*
** EPITECH PROJECT, 2020
** my compute square root by Amoz PAY
** File description:
** find the square root of an integer if the square root is an integer
*/

int my_compute_square_root(int nb)
{
    int diviseur = 46342;
    int result;

    if (nb == 1)
        return (1);
    if (nb < 1)
        return (0);
    while (diviseur > 1) {
        result = nb / diviseur;
        if (diviseur == result && nb % diviseur == 0)
            return (diviseur);
        diviseur--;
    }
    return (0);
}
