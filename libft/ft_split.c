/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:20:23 by hsim              #+#    #+#             */
/*   Updated: 2023/11/06 19:45:18 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	countstr(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	if (*s && s[i - 1] != c)
		count++;
	return (count);
}

static int	countword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/*
 * skips if the split char is in front
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**tab;

	if (!s)
		return (NULL);
	while (*s && s[0] == c)
		s++;
	tab = (char **)malloc((countstr(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	x = 0;
	while (countstr(s, c) > 0)
	{
		tab[x] = (char *)malloc((countword(s, c) + 1) * sizeof(char));
		i = 0;
		while (*s && *s != c)
			tab[x][i++] = *s++;
		tab[x][i] = '\0';
		while (*s && *s == c)
			s++;
		x++;
	}
	tab[x] = NULL;
	return (tab);
}
/*
#include <stdio.h>
int	main()
{
	char	**result;
	int		i;
	
	i = 0;
	result = ft_split("++++sasw++saww+sawaawa++++ ", '+'); 
	while (i < 4)
		printf("%s\n", result[i++]);
}
*/
/*
|note|
if malloc fails, return NULL
splitting s with c as delimiter
the array ends with a NULL pointer
*/
