/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:11:46 by hsim              #+#    #+#             */
/*   Updated: 2023/11/01 19:22:29 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char dest[11] = "kiki";
	char source[] = "";
	int n = 2;
	printf("%lu\n", ft_strlcpy(dest, source, n));
	printf("%s\n", dest);
}
*/
/*
 copy strings up to n and NUL terminate if there is room
 n include NULL
 return strlen(src)
 do not handle overflow, will segfault
*/
