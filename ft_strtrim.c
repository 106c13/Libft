/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:26:24 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/25 15:45:59 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (in_set(s1[start], set))
	{
		start++;
		if (!s1[start])
			return (0);
	}
	return (start);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	end -= 1;
	while (in_set(s1[end], set))
	{
		end--;
		if (end + 1 == 0)
			return (0);
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	end;
	size_t	start;

	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end == 0)
		len = 0;
	else
		len = end - start + 1;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, (s1 + start), len);
	str[len] = '\0';
	return (str);
}
