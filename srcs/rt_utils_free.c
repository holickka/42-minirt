/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:49 by hsim              #+#    #+#             */
/*   Updated: 2025/04/21 13:30:15 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_one(void *vars)
{
	if (!vars)
		return ;
	free(vars);
	vars = NULL;
}

/* 
 * consolidate all mallocs and free when exit program
 * indicator controls what to free
 */
void	free_malloc(t_vars *vars, int indicator)
{
	if (!vars)
		return ;
	// free_assign_hsv(vars->hsv, 3);
	free_one(vars->mlxconnect);
	if (indicator > 0)
	{
		// free_one(vars->z_array);
		// free_assign_hsv(vars->hsv_array, 3);
	}
}