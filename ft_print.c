#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"




static void	ft_printstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}


char *ft_ptos(void *ptr) 
{
    unsigned long addr;
    char *str;
    int size;

    addr = (unsigned long)ptr;
    size = 1;
    while (addr > 0)
    {
        addr = addr / 2;
        size++;
    }
    size = size / 4 + 2;
    str = malloc((size + 1) * sizeof(char));
    str[0] = '0';
    str[1] = 'x';
    str[size] = '\0';
    addr = (unsigned long)ptr;
    while(size > 2)
    {
        str[size - 1] = "0123456789abcdef"[addr % 16];
        addr /= 16;
        size--;
    }
    return str;
}


static char *ft_converter(const char *input, va_list *args)
{
    if (*input == 'd') 
        return (ft_itoa(va_arg(*args, int)));
    else if (*input == 'c')
    {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = (char)va_arg(*args, int);
        result[1] = '\0';
        return (result);
    }
    else if (*input == 's')
    	return (ft_strdup(va_arg(*args, char *)));
    else if (*input == 'p')
        return (ft_ptos(va_arg(*args, void *)));

    return NULL;
}

int ft_printf(const char *input, ...) {
    va_list args;
    va_start(args, input);
    char *str;

    while (*input) {
        if (*input == '%')
        {
            str = ft_converter(input + 1, &args);

            ft_printstr(str);
            free(str);
            input++;
        }
        else
            write(1, input, 1);
        input++;
    }
    va_end(args);
    return 0;
}

int main() {
    int a = 10;
    ft_printf("%p %d, %p, %c", a, 12301031230, "123", 'c');
    return 0;
}
