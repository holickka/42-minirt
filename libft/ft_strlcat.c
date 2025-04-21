/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:12:45 by hsim              #+#    #+#             */
/*   Updated: 2024/12/27 22:23:14 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;
	char	*oridest;

	if (!dest || !src)
		return (0);
	destlen = ft_strlen(dest);
	oridest = dest;
	i = 0;
	if (n < ft_strlen(dest))
		return (n + ft_strlen(src));
	if (n < 0)
		n = ft_strlen(src) + ft_strlen(dest);
	while (dest[i])
		dest++;
	while (destlen + 1 < n-- && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (ft_strlen(src) + destlen);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char dest[10] = "kakax";
	char src[] = "abcd";
	printf("%lu\n", ft_strlcat(dest, src, -1));
	printf("%s\n", dest);
}
*/
/*
 |note|
 concatenates src to dest size >= dest
 NUL terminate if theres room
 n = total strlen created
 need to include NUL in n number 
 does not handle overflow

 n < strlen(dest), return n + strlen(src)
 n >= strlen(dest), return strlen(src) + strlen(dest)
 n < 0, cat all src to dest, return (strlen(src) + strlen(dest))
 */
