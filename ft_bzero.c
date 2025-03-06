/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 106c13   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:52:45 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/21 17:52:26 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*byte_ptr;
	size_t			i;

	byte_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (s);
}
