/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:40:36 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 18:01:19 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (!str)
		return (0);
	if (!*to_find)
		return ((char *)str);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			x = 0;
			while (str[i + x] && str[i + x] == to_find[x] && i + x < len)
				x++;
			if (to_find[x] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_strnstr(NULL, NULL, 9));
}
*/
/*
 locate 1st occurence of to_find in str, return pointer to 1st occur
 len = 1st x chars to search in str
 if to_find == '\0', return str
 if str == '\0', return NULL
 if not found, return NULL 
 */
