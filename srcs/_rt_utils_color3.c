/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:09:57 by hsim              #+#    #+#             */
/*   Updated: 2025/05/04 19:47:58 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * Child of function lerp_hsv
 * Modifies color value according to z height of the point
 */
static void	lerp_hsv_high(t_vars vars, int *hsv_return, int z, int min_max)
{
	int	res[3];

	if (!vars.hsv[HIGH] || !hsv_return)
		return ;
	if (z < 0)
		z *= -1;
	res[H] = (((float)vars.hsv[HIGH][H] - vars.hsv[LOW][H]) / min_max) * z;
	res[S] = (((float)vars.hsv[HIGH][S] - vars.hsv[LOW][S]) / min_max) * z;
	res[V] = (((float)vars.hsv[HIGH][V] - vars.hsv[LOW][V]) / min_max) * z;
	hsv_return[H] = vars.hsv[LOW][H] + res[H];
	hsv_return[S] = vars.hsv[LOW][S] + res[S];
	hsv_return[V] = vars.hsv[LOW][V] + res[V];
}

/*
 * Child of function lerp_hsv
 * Modifies color value according to z height of the point
 */
static void	lerp_hsv_neg(t_vars vars, int *hsv_return, int z, int min_max)
{
	int	res[3];

	if (!vars.hsv[NEG] || !hsv_return)
		return ;
	if (z < 0)
		z *= -1;
	res[H] = ((float)(vars.hsv[NEG][H] - vars.hsv[LOW][H]) / min_max) * z;
	res[S] = ((float)(vars.hsv[NEG][S] - vars.hsv[LOW][S]) / min_max) * z;
	res[V] = ((float)(vars.hsv[NEG][V] - vars.hsv[LOW][V]) / min_max) * z;
	hsv_return[H] = vars.hsv[LOW][H] + res[H] + ROUND_UP;
	hsv_return[S] = vars.hsv[LOW][S] + res[S] + ROUND_UP;
	hsv_return[V] = vars.hsv[LOW][V] + res[V] + ROUND_UP;
}

/*
 * Child function of assign_hsv, by default assigns to hsv[LOW]
 * Assigns color according to point height
 * -1 =there is no assigned color to the point
 *
 * Uses malloc
 */
void	compare_n_assign_0(t_vars *vars, int z_target, float ratio,
		bool b_z_nextrow)
{
	int	z;

	z = vars->z_array[z_target];
	if (vars->hsv_array[H][z_target] != -1 && !vars->keys.b_def_color)
	{
		vars->hsv_tmp[NOW] = create_hsv(vars->hsv_array[H][z_target],
				vars->hsv_array[S][z_target], vars->hsv_array[V][z_target]);
	}
	else
		vars->hsv_tmp[NOW] = create_hsv(vars->hsv[LOW][H], vars->hsv[LOW][S],
				vars->hsv[LOW][V] * ratio);
	if (z > 0 && (vars->hsv_array[H][z_target] == -1 || vars->keys.b_def_color))
		lerp_hsv_high(*vars, vars->hsv_tmp[NOW], z, vars->z_max[b_z_nextrow]);
	else if (z < 0 && (vars->hsv_array[H][z_target] == -1
		|| vars->keys.b_def_color))
		lerp_hsv_neg(*vars, vars->hsv_tmp[NOW], z, vars->z_neg[b_z_nextrow]);
	if (z > 0 || z < 0 || (vars->hsv_array[H][z_target] != -1
		&& !vars->keys.b_def_color))
		vars->hsv_tmp[NOW][V] *= ratio;
	if (!vars->hsv_tmp[NOW])
	{
		ft_printf("🚨 Error at z=%d, map_node=%d\n", z, z_target);
		free_malloc(vars, 1);
		exit(0);
	}
}

/*
 * Child function of assign_hsv, by default assigns to hsv[LOW]
 * Assigns color according to point height
 * -1 =there is no assigned color to the point
 * Uses malloc
 */
void	compare_n_assign_1(t_vars *vars, int z_target, float ratio,
		bool b_z_nextrow)
{
	int	z;

	z = vars->z_array[z_target];
	if (vars->hsv_array[H][z_target] != -1 && !vars->keys.b_def_color)
	{
		vars->hsv_tmp[NEXT] = create_hsv(vars->hsv_array[H][z_target],
				vars->hsv_array[S][z_target], vars->hsv_array[V][z_target]);
	}
	else
		vars->hsv_tmp[NEXT] = create_hsv(vars->hsv[LOW][H], vars->hsv[LOW][S],
				vars->hsv[LOW][V] * ratio);
	if (z > 0 && (vars->hsv_array[H][z_target] == -1 || vars->keys.b_def_color))
		lerp_hsv_high(*vars, vars->hsv_tmp[NEXT], z, vars->z_max[b_z_nextrow]);
	else if (z < 0 && (vars->hsv_array[H][z_target] == -1
		|| vars->keys.b_def_color))
		lerp_hsv_neg(*vars, vars->hsv_tmp[NEXT], z, vars->z_neg[b_z_nextrow]);
	if (z > 0 || z < 0 || (vars->hsv_array[H][z_target] != -1
		&& !vars->keys.b_def_color))
		vars->hsv_tmp[NEXT][V] *= ratio;
	if (!vars->hsv_tmp[NEXT])
	{
		ft_printf("🚨 Error at z=%d, map_node=%d\n", z, z_target);
		free_malloc(vars, 1);
		exit(0);
	}
}
