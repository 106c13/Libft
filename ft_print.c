#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "tmp.h"

static char	*ft_ltoa(char type, void *num)


static void	ft_printstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

static char *convert_to_string(char type, va_list *args) {
    if (type == 'd') 
        return ft_itoa(va_arg(*args, int));
    else if (type == 'c')
    {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = (char)va_arg(*args, int);
        result[1] = '\0';
        return (result);
    }
    else if (type == 's')
    	return (va_arg(*args, char *));
    else if (type == 'lld')
    	return (ft_ltoa(type, ))

    return NULL;
}

int ft_printf(const char *input, ...) {
    va_list args;
    va_start(args, input);
    char *str;

    while (*input) {
        if (*input == '%')
        {
            str = convert_to_string(*(input + 1), &args);
            if (str != NULL)
            {
                ft_printstr(str);
                free(str);
            }
            input++;  // Skip over the format specifier
        }
        else
            write(1, input, 1);
        input++;
    }
    va_end(args);
    return 0;
}

int main() {
    ft_printf("%lld", 9223372036854775807);
    return 0;
}
