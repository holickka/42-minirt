/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:54:48 by hsim              #+#    #+#             */
/*   Updated: 2024/12/27 21:41:39 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	convert_to_int(char target, int *res)
{
	if (target >= '0' && target <= '9')
		*res += (target - '0');
	else if (target >= 'a' && target <= 'f')
		*res += (target - 'a' + 10);
	else if (target >= 'A' && target <= 'F')
		*res += (target - 'A' + 10);
}

/* 
 * Converts base number to integer
 * test with 7CFF
 */
int	ft_basetoi(char *base, char *s, int n)
{
	int	baselen;
	int	res;

	baselen = ft_strlen(base);
	res = 0;
	while (s[0] && (n > 0))
	{
		res *= baselen;
		if (s[0] != '\0' || s[0] != '\n')
			convert_to_int(s[0], &res);
		s++;
		n--;
	}
	return (res);
}
