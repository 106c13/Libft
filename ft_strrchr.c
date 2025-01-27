/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:19:56 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/23 16:10:36 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	c %= 256;
	ptr = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			ptr = (char *)str;
		str++;
	}
	if (*str == c)
		ptr = (char *)str;
	return (ptr);
}
