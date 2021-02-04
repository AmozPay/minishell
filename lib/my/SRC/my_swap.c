/*
** EPITECH PROJECT, 2020
** my_swap by Amoz PAY
** File description:
** Swaps the content of 2 integers.
*/

int my_put_nbr(int nb);

void my_swap(int *a, int *b)
{
    int buffer_a = *a;
    int buffer_b = *b;

    *b = buffer_a;
    *a = buffer_b;
}
