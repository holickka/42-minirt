/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:31:35 by hsim              #+#    #+#             */
/*   Updated: 2023/10/27 20:31:36 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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
