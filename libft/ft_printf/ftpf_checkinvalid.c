/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:21:47 by hsim              #+#    #+#             */
/*   Updated: 2024/01/24 15:38:12 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_checkinvalid(char *str)
{
	int		i;
	char	*errorpath;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[++i]) == NULL)
		{
			errorpath = ft_substr(&str[i], 0, 5);
			ft_printf("Invalid identifier detected at index %d, ->%s<-\
 Abort!\n", i, errorpath);
			free(errorpath);
			return (1);
		}
	}
	return (0);
}
