/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:35:04 by hsim              #+#    #+#             */
/*   Updated: 2023/10/27 17:35:27 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mys1;
	unsigned char	*mys2;

	mys1 = (unsigned char *)s1;
	mys2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (mys1[i] != mys2[i])
			return (mys1[i] - mys2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char c[] = "hralow";
	char d[] = "hra";
	printf("%d\n", memcmp(c, d, 3));
}
*/
/*
 compare byte s1 to byte s2 to n byte
 byte of s1 = byte of s2, return 0 
 if not, return difference 1st 2 differing byte (as unsigned char)
 n = 0, return 0
 compare up to null terminator
 does not handle overflow, if n > strlen, will segfault

 ! when s1 || s2 is empty,
 will access unalloc mem to byte specified in n
 */
