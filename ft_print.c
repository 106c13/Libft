#include <stdio.h>
#include "libft.h"
#include "libftprintf.h"

void format_parser(const char **format, t_arg *arg)
{
    // find width
    // find precision
    // find length
    find_flag(format, arg);
    find_width(format, arg);
    find_precision(format, arg);
    find_specifier(format, arg);
}

void print_surplus(int size, char pad, int *count)
{
    while (size > 0)
    {
        ft_cputchar(pad, count);
        size--;
    }
}

void print_n_zeros(int n, int *count)
{
    while (n-- > 0)
        ft_cputchar('0', count);
}

void print_negative_num(char *str, int *count, int width)
{
    ft_cputchar('-', count);
    print_surplus(width - ft_strlen(str), '0', count);
    str++;
    ft_cputstr(str, count);
}

void print_flag(t_arg *arg, char **str, int *count)
{
    if (arg->flag[1] && **str != '-')
        ft_cputchar('+', count);
    else if (arg->flag[2] && **str != '-')
        ft_cputchar(' ', count);
    else if (**str == '-')
    {
        ft_cputchar('-', count);
        (*str)++;
        (arg->width)--;
    }
}

void print_int(int num, t_arg *arg, int *count)
{
    char *str;

    str = ft_itoa(num);
    if ((arg->flag[1] || arg->flag[2]) && num >= 0)
        arg->width--;
    if (arg->flag[3] && !arg->flag[0])
    {
        print_flag(arg, &str, count);
        print_surplus(arg->width - ft_strlen(str), '0', count);
        ft_cputstr(str, count);
    }
    else if (!arg->flag[0])
    {
        print_surplus(arg->width - ft_strlen(str), ' ', count);
        print_flag(arg, &str, count);
        ft_cputstr(str, count);
    }
    else if (arg->flag[0])
    {
        print_flag(arg, &str, count);
        ft_cputstr(str, count);
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    }
    free(str);
}

void print_char(char c, t_arg *arg, int *count)
{
    if (arg->flag[0])
    {
        ft_cputchar(c, count);
        print_surplus(arg->width - 1, ' ', count);
    }
    else
    {
        print_surplus(arg->width - 1, ' ', count);
        ft_cputchar(c, count);
    }
}

void print_hex(unsigned int num, t_arg *arg, int *count, int cap)
{
    char *str;
    
    str = ft_dtoh((unsigned long)num, cap);
    if (!str)
        return ;
    if (arg->flag[4])
        arg->width -= 2;
    if ((unsigned int)arg->prec > ft_strlen(str) && arg->prec > 0)
        arg->width -= arg->prec - ft_strlen(str);
    if (!arg->flag[0] && !arg->flag[3])
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    if (arg->flag[4] && num != 0)
        ft_cputstr("0x", count);
    if (!arg->flag[0] && arg->flag[3])
        print_surplus(arg->width - ft_strlen(str), '0', count);
    print_n_zeros(arg->prec - ft_strlen(str), count);
    if (!(arg->prec == 0 && num == 0))
        ft_cputstr(str, count);
    if (arg->flag[0])
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    free(str);
}

void print_string(char *str, t_arg *arg, int *count)
{
    int dup;

    dup = 0;
    if ((unsigned int)arg->prec < ft_strlen(str) && arg->prec >= 0)
    {
        str = ft_strdup(str);
        str[arg->prec] = '\0';
        dup = 1;
    }
    if (!arg->flag[0])
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    ft_cputstr(str, count);
    if (arg->flag[0])
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    if (dup)
        free(str);
}

void print_pointer(void *ptr, t_arg *arg, int *count)
{
    char *str;
    
    str = ft_dtoh((unsigned long)ptr, 0);
    if (!arg->flag[0])
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    ft_cputstr("0x", count);
    ft_cputstr(str, count);
    if (arg->flag[0])
        print_surplus(arg->width - ft_strlen(str), ' ', count);
}

void print_unsigned(unsigned int num, t_arg *arg, int *count)
{
    char *str;

    str = ft_utoa(num);
    if ((arg->flag[1] || arg->flag[2]))
        arg->width--;
    print_flag(arg, &str, count);
    if (arg->flag[3] && !arg->flag[0])
    {
        print_surplus(arg->width - ft_strlen(str), '0', count);
        ft_cputstr(str, count);
    }
    else if (!arg->flag[0])
    {
        print_surplus(arg->width - ft_strlen(str), ' ', count);
        ft_cputstr(str, count);
    }
    else if (arg->flag[0])
    {
        ft_cputstr(str, count);
        print_surplus(arg->width - ft_strlen(str), ' ', count);
    }
    free(str);
}

void string_builder(const char **format, va_list *args, int *count)
{
    t_arg arg;
    ft_memset(arg.flag, 0, sizeof(arg.flag));
    format_parser(format, &arg);
    if (arg.spec == 0)
        print_int(va_arg(*args, int), &arg, count);
    else if (arg.spec == 1)
        print_char((char)va_arg(*args, int), &arg, count);
    else if (arg.spec == 2)
        print_string((char *)va_arg(*args, int), &arg, count);
    else if (arg.spec == 3)
        print_hex((unsigned int)va_arg(*args, int), &arg, count, 0);
    else if (arg.spec == 4)
        print_hex((unsigned int)va_arg(*args, int), &arg, count, 1);
    else if (arg.spec == 5)
        print_unsigned((unsigned int)va_arg(*args, int), &arg, count);
    else if (arg.spec == 6)
        print_pointer(va_arg(*args, void *), &arg, count);

}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count;

    count = 0;
    while (*format)
    {
        if (*format == '%')
            string_builder(&format, &args, &count);
        else
            format += ft_cputchar(*format, &count);
    }
    return (count);
}

int main() {
    printf("%d\n", printf("|%#-20.10u|", 4000000000));  // with 10 precision and 20 width
    ft_printf("%d\n", ft_printf("|%#-20.10u|", 4000000000));  // with 10 precision and 20 width

    // Example 2: Zero Padding with a Width of 15
    printf("%d\n", printf("|%0-15u|", 4000000000));  // zero padding, width 15
    ft_printf("%d\n", ft_printf("|%0-15u|", 4000000000));  // zero padding, width 15

    // Example 3: Width of 10 and + Flag
    printf("%d\n", printf("|%+10u|", 4000000000));  // width 10 with `+` flag
    ft_printf("%d\n", ft_printf("|%+10u|", 4000000000));  // width 10 with `+` flag

    // Example 4: Left Alignment with Width 15
    printf("%d\n", printf("|%-15u|", 4000000000));  // left-aligned, width 15
    ft_printf("%d\n", ft_printf("|%-15u|", 4000000000));  // left-aligned, width 15

    // Example 5: Width of 10 and # Flag (with prefix)
    printf("%d\n", printf("|%#10u|", 4000000000));  // width 10 with `#` flag (prefix)
    ft_printf("%d\n", ft_printf("|%#10u|", 4000000000));  // width 10 with `#` flag (prefix)

    // Example 6: Width of 10 with precision of 5
    printf("%d\n", printf("|%10.5u|", 4000000000));  // width 10 with precision 5
    ft_printf("%d\n", ft_printf("|%10.5u|", 4000000000));  // width 10 with precision 5

    // Example 7: Width of 10, precision of 5, and 0 padding
    printf("%d\n", printf("|%010.5u|", 4000000000));  // zero-padded with width 10 and precision 5
    ft_printf("%d\n", ft_printf("|%010.5u|", 4000000000));  // zero-padded with width 10 and precision 5

    // Example 8: Width 15 with space for positive number
    printf("%d\n", printf("|% 15u|", 4000000000));  // width 15 with space for positive number
    ft_printf("%d\n", ft_printf("|% 15u|", 4000000000));  // width 15 with space for positive number

    // Example 9: Just the width without any additional flags
    printf("%d\n", printf("|%15u|", 4000000000));  // width 15
    ft_printf("%d\n", ft_printf("|%15u|", 4000000000));  // width 15

    // Example 10: Zero padding with precision
    printf("%d\n", printf("|%010.10u|", 4000000000));  // zero-padded with width 10 and precision 10
    ft_printf("%d\n", ft_printf("|%010.10u|", 4000000000)); 
    return 0;
}