/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:02:46 by hsim              #+#    #+#             */
/*   Updated: 2023/10/27 17:02:47 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned long	i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
		ptr[i++] = c;
	return (b);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	int i;

	i = 0;
//	char str[10] = "what is";
	int str[10] = {-10, -10, 19};
	ft_memset(&str[1], 0, 3 * sizeof(int));
//	memset(str, 'x', sizeof(str));
	while (i < 3)
		printf("%d\n", str[i++]);
}
*/
/*
|notes|
initialize entire string with same char
replace string partially
replace what is in b to c
does not handle overflow
*/
