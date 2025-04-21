/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:59:26 by hsim              #+#    #+#             */
/*   Updated: 2023/11/06 19:04:57 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#define UINT_MAX 4294967295

void	*ft_calloc(size_t count, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (n != 0 && count > UINT_MAX / n)
		return (NULL);
	tab = (unsigned char *)malloc(count * n);
	if (tab != NULL)
	{
		while (i < count * n)
			tab[i++] = 0;
		return (tab);
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	int	*arr;
	unsigned int	i;
	unsigned int	n;

	n = 4294967294;
	i = 0;
	arr = (int *)calloc(69999, 69999);

//	while(i < n)
//		printf("%d ", arr[i++]);
}
*/
/*
 allocate space for block count in byte size as defined in n
 allocated mem is filled with bytes val of 0
 system malloc max size = sq of 2147483647
 system calloc max size = sq of 69999 ~ 700000
 mine function define max size = sq of 65535 (size_t max)
*/
