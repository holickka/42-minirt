/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:17:03 by hsim              #+#    #+#             */
/*   Updated: 2023/10/27 17:17:04 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	else if (c >= 0101 && c <= 0132)
		c -= 4;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_tolower(3));
}
*/
/*
 notes
 if enter octal, return decimal ascii
 */
