/*
** EPITECH PROJECT, 2020
** my_printf - Amoz PAY
** File description:
** criterion tests - loading the output **char
*/

#include "my.h"
#include "my_printf.h"
#include <criterion/criterion.h>

Test(load_str, no_flag)
{
    int i = 0;

    cr_expect_str_eq(load_str("Hello World!\n", &i), "Hello World!\n");
}

Test(load_str, with_flag)
{
    int i = 0;

    cr_expect_str_eq(load_str("Hello %World!\n", &i), "Hello ");
}

Test(load_conversion, simple_flag)
{
    int i = 0;

    cr_expect_str_eq(load_conversion("%dHelloWorld!\n", &i), "%d");
    i = 0;
    cr_expect_str_eq(load_conversion("%iHelloWorld!\n", &i), "%i");
    i = 0;
    cr_expect_str_eq(load_conversion("%uHelloWorld!\n", &i), "%u");
    i = 0;
    cr_expect_str_eq(load_conversion("%xHelloWorld!\n", &i), "%x");
    i = 0;
    cr_expect_str_eq(load_conversion("%XHelloWorld!\n", &i), "%X");
    i = 0;
    cr_expect_str_eq(load_conversion("%oHelloWorld!\n", &i), "%o");
    i = 0;
    cr_expect_str_eq(load_conversion("%sHelloWorld!\n", &i), "%s");
    i = 0;
    cr_expect_str_eq(load_conversion("%cHelloWorld!\n", &i), "%c");
    i = 0;
    cr_expect_str_eq(load_conversion("%SHelloWorld!\n", &i), "%S");
}

Test(load_conversion, complex_flag)
{
    int i = 0;

    cr_expect_str_eq(load_conversion("% 550dHelloWorld!\n", &i), "% 550d");
    i = 0;
    cr_expect_str_eq(load_conversion("%-+02iHelloWorld!\n", &i), "%-+02i");
    i = 0;
    cr_expect_str_eq(load_conversion("%#25uHelloWorld!\n", &i), "%#25u");
    i = 0;
    cr_expect_str_eq(load_conversion("%#12xHelloWorld!\n", &i), "%#12x");
}

Test(load_output, strings)
{
    int i = 0;

    cr_expect_str_eq(load_output("%025dSalutToi\n", &i), "%025d");
    cr_expect_str_eq(load_output("SalutToi\n%025d", &i), "SalutToi\n");
}
