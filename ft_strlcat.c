/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:28:04 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/23 19:17:31 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lst;

	i = 0;
	j = ft_strlen(dest);
	if (size <= j)
		return (size + ft_strlen(src));
	lst = j;
	while (src[i] != '\0')
	{
		if (j + i < size)
		{
			dest[j + i] = src[i];
			lst = j + i;
		}
		i++;
	}
	if (lst == size - 1)
		dest[lst] = '\0';
	else if (lst < size)
		dest[lst + 1] = '\0';
	return (j + i);
}
