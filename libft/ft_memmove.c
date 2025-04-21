/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:10:30 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 17:53:46 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned long	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (src < dest)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char c[] = "Hellowhale";
	ft_memmove(c, c + 5, 3);
	printf("%s\n", c);
}
*/
/*
 copy len bytes from src to dest
 returns dest
 does not NULL terminate, will overflow(segfault)
 two strings may overlap
 overlap is like overwrite, 
 eg copy endpart of string to beginning of string
 */
