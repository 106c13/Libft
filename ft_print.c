#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "tmp.h"


static char	*convert_to_string(char c, )
{

	if (c == 'd')
		return (ft_i)

}


int	ft_print(const char *input, ...)
{
	va_list args;  
	va_start(args, input);  
	int		i;
	int 	total_printed;
	char	*str;

	i = va_arg(args, int);
	total_printed = 0;
	while (*input)
	{
		if (*input == '%')
			str = convert_to_string(*(input + 1), )
	}
	va_end(args);
	return (0);
}


int	main()
{
	char	*s;
	char	*str = "0123456789";
	ft_print("%d %d %d", 2, 3, 0);
	return 0;
}