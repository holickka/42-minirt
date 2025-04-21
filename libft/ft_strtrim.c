/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:20:08 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 18:21:40 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		x;
	char	*tab;

	a = 0;
	x = 0;
	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, s1[0]))
		s1++;
	x = ft_strlen(s1);
	while (*s1 && ft_strrchr(set, s1[x - 1]))
		x--;
	tab = (char *)malloc((x + 1) * sizeof(char));
	if (tab != NULL)
	{
		while (a < x)
			tab[a++] = *s1++;
		tab[a] = '\0';
		return (tab);
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strtrim("+-saw++awwa++asd-+", "+-"));
}
*/
/*
|note|
trim string when set is detected
remove beginning & end of s1 if set is detected there
if allocation success, return trimmed string
if allocation failed, return NULL
*/
