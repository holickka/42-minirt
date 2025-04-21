/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:27:48 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 18:56:49 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	int		i;

	if (!s || !f)
		return (NULL);
	i = -1;
	tab = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (tab != NULL)
	{
		while (s[++i])
			tab[i] = f(i, s[i]);
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
/*
#include <ctype.h>
#include <stdio.h>
char	uppercase(unsigned int i, char s)
{
	if (i % 2 == 0)
		return ((char)toupper((int)s));
	return ((char)tolower((int)s));
}
int	main()
{
	printf("%s\n", ft_strmapi("helloww", &uppercase));
}
*/
/*
|note|
apply function f to each char in s, 
index of char s = 1st argument of function f
creates new string with malloc
*/
