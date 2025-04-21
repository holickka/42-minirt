/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:30:53 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 20:15:36 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	if (*s && *f)
	{
		while (s[++i])
			f(i, &s[i]);
	}
}
/*
void	ft_uppercase(unsigned int n, char *s)
{
	if(s[n] >= 'a' && s[n] <= 'z')
		s[n] = s[n] - 'a' + 'A';
}
#include <stdio.h>
int	main()
{
	char c[] = "hellow";
	ft_striteri(c, &ft_uppercase);
	printf("%s\n", c);
}
*/
/*
|notes|
applies function f on each char s
*/
