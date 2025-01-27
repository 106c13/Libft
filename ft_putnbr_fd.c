/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:07:01 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/26 15:58:42 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	char			c;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n > 0)
		i = (unsigned int)n;
	else
	{
		write(fd, "-", 1);
		i = (unsigned int)(-n);
	}
	if (n / 10 != 0)
		ft_putnbr_fd(i / 10, fd);
	c = 48 + i % 10;
	write(fd, &c, 1);
}
