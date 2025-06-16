/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:49 by hsim              #+#    #+#             */
/*   Updated: 2025/06/15 22:43:47 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_one(void *vars)
{
	if (!vars)
		return ;
	free(vars);
	vars = NULL;
}

void	free_assign_hsv(int **hsv, int free_count)
{
	if (!hsv)
		return ;
	while (free_count > 0)
	{
		free(hsv[--free_count]);
		hsv[free_count] = NULL;
	}
}

/* 
 * consolidate all mallocs and free when exit program
 * indicator controls what to free
 */
void	free_malloc(t_vars *vars, int indicator)
{
	if (!vars)
		return ;
	// free_assign_hsv(vars->color_bg, 2);
	free_one(vars->mlxconnect);
	free(vars->sph);
	if (indicator > 0)
	{
		// free_one(vars->z_array);
		// free_assign_hsv(vars->hsv_array, 3);
	}
}