/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:31:35 by hsim              #+#    #+#             */
/*   Updated: 2023/11/14 20:36:41 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
/*
int	main()
{
	char c = 'a';
	ft_putchar_fd(c, 1);
}
*/
/*
|note|
file descriptor
0 = read from stdin (read input frpm keyboard)
1 = write to stdout (output to video screen)
2 = write to stderror
*/
