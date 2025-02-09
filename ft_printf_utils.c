#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>
int ft_cputchar(char c, int *count)
{
    write(1, &c, 1);
    (*count)++;
    return (1);
}

void ft_cputstr(const char *str, int *count)
{
    while (*str)
    {
        ft_cputchar(*str, count);
        str++;
    }
}

char *ft_dtoh(unsigned long num, int cap) 
{
    int len;
    unsigned long temp;
    char *str;

    temp = num;
    len = 1;
    while (temp /= 16)
        len++;
    str = (char *)malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    while (len--)
    {
        if (!cap)
            str[len] = "0123456789abcdef"[num % 16];
        else
            str[len] = "0123456789ABCDEF"[num % 16];
        num /= 16;
    }
    return (str);
}


char *ft_utoa(unsigned int num)
{
    char    *str;
    int     size;
    unsigned int temp;

    if (num == 0)
        return (ft_strdup("0"));
    temp = num;
    size = 1;
    while (temp /= 10)
        size++;
    str = malloc((size + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);
    str[size] = '\0';
    while (num != 0)
    {
        str[size - 1] = (num % 10) + 48;
        num /= 10;
        size--;
    }
    return (str);
}