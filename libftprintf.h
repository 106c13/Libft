#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <unistd.h>
#include <stdarg.h>

typedef struct s_arg
{
    int spec;
    int flag[5];
    int width;
    int prec;
    int lenght;
}   t_arg;

int ft_cputchar(char c, int *count);
void ft_cputstr(const char *str, int *count);
char *ft_dtoh(unsigned long num, int cap); 
char *ft_utoa(unsigned int num);

void find_flag(const char **format, t_arg *arg);
void find_width(const char **format, t_arg *arg);
void find_specifier(const char **format,  t_arg *arg);
void find_precision(const char **format, t_arg *arg);

void format_parser(const char **format, t_arg *arg);
void string_builder(const char **format, va_list *args, int *count);


#endif
