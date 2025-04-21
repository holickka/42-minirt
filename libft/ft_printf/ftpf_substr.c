/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:16:59 by hsim              #+#    #+#             */
/*   Updated: 2024/01/23 16:12:37 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	ft_bzero(tab, (len + 1));
	while (i < len)
		tab[i++] = s[start++];
	return (tab);
}
/*
#include <stdio.h>
int	main()
{
	char c[] = "Melloe";
	char *dest;
	dest = ft_substr(c, 2, 20);
	printf("%s\n", dest);
}
*/
/*
 create newstr from s[start] to s[len], return newstr
 i assume len doesnt include '\0'
 if allocation fail, return NULL
 */
