/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:09:28 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 17:52:25 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*tempdest;
	unsigned char	*tempsrc;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (tempdest);
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (tempdest);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char dest[10] = "abcdefghi";
	char src[] = "whae";
	int	n;

	n = 0;
	ft_memcpy(dest, src, n);
	printf("%s\n", dest);
}
*/
/*
 |notes|
 copy n bytes from src to dest
 will overwrite what is in dest up to n
 restrict is for note to compiler that dest and src
 if dest is empty, return dest
 does not handle overflow, will segfault

 *restrict is only to tell compiler that dest and src
 should not overlap
 */
