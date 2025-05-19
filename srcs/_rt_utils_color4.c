/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rt_utils_color4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:16:51 by hsim              #+#    #+#             */
/*   Updated: 2025/05/04 19:53:43 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * Child function to get_minmax_z
 * assigns start index depending on flag status
 */
static void	assign_start_pt(t_vars *vars, int *start, int map_width, \
							int map_height)
{
	if (!vars)
		return ;
	if (vars->keys.flag == 1)
	{
		start[NOW] = (vars->map_size - 1 - (map_width * (map_height - 1)));
		start[NEXT] = (vars->map_size - 1 - (map_width * (map_height - 2)));
	}
	else
	{
		start[NOW] = ((map_width * map_height) - 1);
		start[NEXT] = ((map_width * (map_height - 1)) - 1);
	}
}

/* 
 * Gets min & max z value for current row & next row
 * NOW here indicates current row, NEXT indicates next row
 * result used in compare_height_hsv for color gradient
 */
void	get_minmax_z(t_vars *vars, int map_width, int map_height)
{
	int	start[2];

	if (!vars)
		return ;
	assign_start_pt(vars, start, map_width, map_height);
	vars->z_max[NOW] = compare_z_value('+', *vars, start[NOW]);
	vars->z_neg[NOW] = compare_z_value('-', *vars, start[NOW]);
	if (map_height - 2 >= 0)
	{
		vars->z_max[NEXT] = compare_z_value('+', *vars, start[NEXT]);
		vars->z_neg[NEXT] = compare_z_value('-', *vars, start[NEXT]);
	}
}

static float	get_ratio(t_vars vars, int map_height)
{
	float	ratio;
	float	min_unit;

	min_unit = ((1.0 - vars.color_brightness) / (vars.map_height - 1));
	if (vars.keys.b_z_nextrow == 1)
		ratio = (vars.color_brightness + \
				(min_unit * (vars.map_height - map_height)));
	else if (vars.keys.b_z_nextrow == 0)
		ratio = (vars.color_brightness + \
				(min_unit * (vars.map_height - 1 - map_height)));
	else
		ratio = 1;
	return (ratio);
}

/* 
 * assigns both z value and hsv at the same time 
 * uses malloc, need to free after drawing is done
 */
void	assign_hsv(t_vars *vars, int map_height, int z_now, int z_next)
{
	float	ratio;

	vars->z_tmp[NOW] = vars->z_array[z_now];
	vars->z_tmp[NEXT] = vars->z_array[z_next];
	ratio = get_ratio(*vars, map_height);
	if (!(vars->hsv_tmp[NOW]))
		compare_n_assign_0(vars, z_now, ratio, 0);
	compare_n_assign_1(vars, z_next, ratio, vars->keys.b_z_nextrow);
}
