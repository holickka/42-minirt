/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:04:45 by hsim              #+#    #+#             */
/*   Updated: 2025/05/07 13:33:05 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* mallocs a sph_ptr and writes all to NULL */
int	malloc_sph_ptr(t_sph **dest, int num)
{
	if (num <= 0)
		return (0);
	*dest = (t_sph *)malloc(sizeof(t_sph) * num);
	if (!(*dest))
	{
		ft_perror("🚨 malloc_sph_ptr failed!", 0);
		return (0);
	}
	// while (--num >= 0)
		// (*dest)->rad = -1;
	return (1);
}
