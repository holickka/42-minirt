/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:26:21 by hsim              #+#    #+#             */
/*   Updated: 2023/11/01 21:24:55 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			x = i + 1;
			while (s[x])
			{
				if (s[x] == (unsigned char)c)
					i = x;
				x++;
			}
		}
		if (s[x] == '\0')
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	printf("%s\n", ft_strrchr("abc+deff++asdc+a", '\0'));
}
*/
/*
int c will be converted to char
locates last occurence of c
returns pointer to located char
if not found, return NULL
*/
