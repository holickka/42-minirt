/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:06:06 by hsim              #+#    #+#             */
/*   Updated: 2024/01/23 16:12:41 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
		temp[i++] = 0;
}
/*
#include <stdio.h>
#include <strings.h>
int	main()
{
	int	i;
	int	n;
//	int	x[] = {10, 10, 9};
	char	x[] = "what";

	i = 0;
	n = 2;
	ft_bzero(x, n * sizeof(char));
	while (i <= n)
		printf("%d\n", x[i++]);
}
*/
/*
|notes|
write n number of 0 to s
(eg n = 5, 0 0 0 0 0)
if n = 0, does nothing

when n > sizeof (*s)
continue write until segfault

didnt include temp[i] in while loop
cz it changes temp to 0
which faults the condition
*/
