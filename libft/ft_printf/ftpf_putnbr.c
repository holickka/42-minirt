/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:33:16 by hsim              #+#    #+#             */
/*   Updated: 2023/11/14 20:36:38 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	nlong;

	nlong = (long)n;
	len = 0;
	if (nlong < 0)
	{
		nlong *= -1;
		len += ft_putchar('-');
	}
	if (nlong >= 10)
	{
		len += ft_putnbr(nlong / 10);
		len += ft_putnbr(nlong % 10);
	}
	if (nlong >= 0 && nlong <= 9)
	{
		nlong += '0';
		len += ft_putchar(nlong);
	}
	return (len);
}
/*
#include <stdio.h>
int	main()
{
//	int x = ft_putnbr(-2147483648);
	int x = printf("-2147483648");
	printf("%d\n", x);
}
*/