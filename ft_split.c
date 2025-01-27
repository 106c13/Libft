/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:52:47 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/23 12:43:47 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*get_string(char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[end - start] = '\0';
	while ((start + i) < end)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

static void	add_list(char const *s, char c, char **list)
{
	int		start;
	int		i;
	int		count;

	i = 0;
	start = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if ((i - start) > 0)
			{
				list[count] = get_string(s, start, i);
				count++;
			}
			start = i + 1;
		}
		i++;
	}
	if ((i - start) > 0)
		list[count] = get_string(s, start, i);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		count;

	count = count_strings(s, c);
	list = malloc((count + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	add_list(s, c, list);
	list[count] = 0;
	return (list);
}
