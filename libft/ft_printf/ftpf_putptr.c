/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:33:16 by hsim              #+#    #+#             */
/*   Updated: 2024/01/22 17:18:46 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(void *n)
{
	int	len;

	ft_putstr("0x");
	len = 2;
	if (!n)
	{
		len += write (1, "0", 1);
		return (len);
	}
	len += ft_putnbr_ux((unsigned long long)n, 'x');
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	char c[] = "Hello";
	int	x = ft_putptr(c);
	printf("__");
	printf("%p\n", c);
	ft_printf("%d\n", x);
}
*/