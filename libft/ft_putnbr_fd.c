/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:33:16 by hsim              #+#    #+#             */
/*   Updated: 2023/10/27 20:33:22 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nlong;

	nlong = (long)n;
	if (nlong < 0)
	{
		nlong *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nlong >= 10)
	{
		ft_putnbr_fd(nlong / 10, fd);
		ft_putnbr_fd(nlong % 10, fd);
	}
	if (nlong >= 0 && nlong <= 9)
	{
		nlong += '0';
		ft_putchar_fd(nlong, fd);
	}
}
/*
int	main()
{
	ft_putnbr_fd(-2147483648, 1);
}
*/
