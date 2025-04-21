/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:13:43 by hsim              #+#    #+#             */
/*   Updated: 2023/11/01 17:13:44 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	numlen(int n)
{
	int		count;
	long	nlong;

	nlong = (long)n;
	count = 0;
	if (nlong < 0)
	{
		nlong = -nlong;
		count++;
	}
	while (nlong >= 10)
	{
		nlong /= 10;
		count++;
	}
	return (count + 1);
}

static void	ft_neg(long *n, char *tab)
{
	if (*n < 0)
	{
		*n *= -1;
		tab[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		count;
	long	nlong;
	long	nb;

	nlong = (long)n;
	count = numlen(n);
	tab = (char *)malloc((count + 1) * sizeof(char));
	if (tab != NULL)
	{
		tab[count] = '\0';
		if (nlong < 0)
			ft_neg(&nlong, tab);
		while (nlong >= 10)
		{
			nb = nlong % 10;
			tab[--count] = ((int)nb + '0');
			nlong /= 10;
		}
		if (nlong >= 0 && nlong <= 9)
			tab[--count] = ((int)nlong + '0');
		return (tab);
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
}
*/
/*
|note|
convert char of int to int
if malloc fails, return NULL
if malloc success, return the string represented by int n
need to handle negative num
1205
5
120
0
12
2
1
*/
