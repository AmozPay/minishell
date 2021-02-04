/*
** EPITECH PROJECT, 2020
** my.h - Amoz Pay
** File description:
** prototypes, includes, typedefs etc...
*/

#ifndef MY_H
#define MY_H

///////////////////////////////////
/////////// INCLUDES //////////////
///////////////////////////////////

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

///////////////////////////////////
//////////// DEFINES //////////////
///////////////////////////////////

#define HEX_BASE "0123456789abcdef"
#define DEC_BASE "0123456789"
#define OCT_BASE "01234567"
#define BIN_BASE "01"
#define CONV_SPEC "oxXbdiucsSp%"
#define FLAGS "# +-0"


///////////////////////////////////
////////// STRUCTURES /////////////
///////////////////////////////////

typedef struct s_sprintf {
    char **output;
    int nb_strings;
} sprintf_t;

///////////////////////////////////
/////////// PROTOTYPES ////////////
///////////////////////////////////
sprintf_t my_sprintf(char const *format, ...);
int is_purcent(char *format);
int is_no_print_str(char *format);
char *replace_no_print(char *format, char *str);
int my_compute_power_rec(int nb, int p);
unsigned long my_put_u_nbr(unsigned long nb);
void format_output(va_list list, int nb_strings, char **output);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int check_result_is_int(long result);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void *my_sort_int_array(int *array, int size);
int my_isalpha(char c);
int my_str_isalpha(char const *str);
int my_islower(char c);
int my_str_islower(char const *str);
int my_strlen(char const *str);
int my_str_isnum(char const *str);
int my_isprintable(char c);
int my_str_isprintable(char const *str);
int my_isupper(char c);
int my_str_isupper(char const *str);
int my_is_alphanum(char c);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
void my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int go_to_next_word(char const *str, int i);
char *add_word(char const *str, int position_init);
int find_nb_words(char const *str);
char **my_str_to_word_array(char const *str);
int my_isalphanum(char c);
int my_isnum(char c);
char *process_flags(char *format, char *str);
char *add_padding_sign(int nb_chars_pad, char sign);
char *replace_ptr(char *format, void *ptr);
int is_ptr(char *format);
void save_u_nbr_base(unsigned long nb, int base_spec, char *dest, int *cmpt);
char *my_save_u_nbr_base(unsigned long nb, int base_spec);
int is_not_letter(char c);
char *add_padding(char *str, int *flags, char *format);
void get_padding(char *format, int *flags);
void get_other_flags(char *format, int *flags);
int is_other_flags(char c);
char *add_alternate_form_x(char *str, char conv_spec);
char *add_alternate_form_o(char *str);
char *add_space_or_sign(char *str, char conv_spec, char space_or_sign);
char *add_other_flags(char *str, int *flags, char *format);
int find_other_flag(char c);
char *save_char_str(char *output, int char_as_int);
char *my_save_nbr_base(long nb, int base_spec);
void save_nbr_base(long nb, int base_spec, char *dest, int *cmpt);
int go_to_next_element(char const *format, int *i, int *count);
int add_conversion(char const *format, int *count, int *i);
int parsing_count(char const *format);
int is_conv_spec(char c);
int is_flag(char c);
int is_str(char *str);
int add_str(char const *format, int *count, int *i);
int is_num_or_dot(char c);
char *load_str(char const *format, int *i);
char *load_conversion(char const *format, int *i);
char *load_output(char const *format, int *i);
char *convert_int(char *str, int arg);
void preload_output(char const *format, char **output, int nb_strings);
int my_printf(char const *format, ...);
int is_nb(char *str);
char *replace_str(char *str, char *str2);
int is_convertible(char c);
char *convert_base(char *str, char last_digit, long arg);
void my_puterr(char const *str);
#endif
