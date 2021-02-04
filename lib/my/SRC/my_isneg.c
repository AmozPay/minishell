/*
** EPITECH PROJECT, 2020
** my_is_neg by Amoz PAY
** File description:
** return the sign N or P according to sign of n
*/

void my_putchar(char);

int my_isneg(int n)
{
    char result;

    if (n < 0){
        result = 'N';
    } else {
        result = 'P';
    }
    my_putchar(result);
    return (0);
}
