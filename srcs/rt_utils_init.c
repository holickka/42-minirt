/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:05:22 by hsim              #+#    #+#             */
/*   Updated: 2025/05/20 18:48:36 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * initialize mlx windows for image rendering
 * mlx_init uses malloc
 */
void	initialize_mlx(t_vars *vars)
{
	vars->mlxconnect = mlx_init();
	if (vars->mlxconnect == NULL)
	{
		free(vars->mlxconnect);
		exit (1);
	}
	vars->mlxwindow = mlx_new_window(vars->mlxconnect, WIN_WIDTH, WIN_HEIGHT, \
"miniRT");
}

void	init_variable(t_vars *vars)
{
	vars->cam_center = new_vector3d(0, 0, 0);
	vars->ray.origin = vars->cam_center; //be careful with this one, maybe copy safer?
	vars->ray.vector = new_vector3d(0, 0, 0);

	vars->ray_bounce = 10;
	vars->sample_per_pixel = 5;
	vars->focal_len = 1;

	vars->color_bg[0] = create_hsv(199, 100, 100);
	vars->color_bg[1] = create_hsv(166, 10, 90);
	// vars->color_bg[1] = create_hsv(225, 62, 40);
	// vars->color_bg[1] = create_hsv(166, 38, 100);

	/* init sphere objects */
	vars->count_sph = 2;
	malloc_sph_ptr(&vars->sph, vars->count_sph);
	vars->sph[0].orig = new_vector3d(0, 0, -1);
	vars->sph[0].rad = 0.5;
	vars->sph[1].orig = new_vector3d(0, -100.5, -1);
	vars->sph[1].rad = 100;

	my_create_image(vars, &vars->img);
}
