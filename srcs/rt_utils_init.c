/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:05:22 by hsim              #+#    #+#             */
/*   Updated: 2025/06/16 18:53:21 by hsim             ###   ########.fr       */
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

/*
 * wrapper function to assign members in target to location & sph_radius
 * target has been malloced before passing to here
 */
t_sph	new_sphere(t_vector3d position, float sph_radius, t_vector3d color, t_uchar mat_type)
{
	t_sph	target;

	target.orig = position;
	target.rad = sph_radius;
	target.mat.albedo = color;
	target.mat.type = mat_type;
	return (target);
}

void	init_variable(t_vars *vars)
{
	vars->cam_center = new_vector3d(0, 0, 0);
	vars->ray.origin = vars->cam_center; //be careful with this one, maybe copy safer?
	vars->ray.vector = new_vector3d(0, 0, 0);

	vars->ray_bounce = 5;
	vars->sample_per_pixel = 100;
	vars->focal_len = 1;

	// vars->color_bg[0] = create_hsv(199, 100, 100);
	// vars->color_bg[1] = create_hsv(166, 10, 90);

	vars->color_bg[0] = new_vector3d(0.5, 0.7, 1);
	vars->color_bg[1] = new_vector3d(1, 1, 1);
	// vars->color_bg[0] = new_vector3d(0, 0.7, 1);
	// vars->color_bg[1] = new_vector3d(0, 1, 1);
	// vars->color_bg[0] = new_vector3d(0, 178, 255);
	// vars->color_bg[1] = new_vector3d(0, 255, 255);
	// vars->color_bg[1] = create_hsv(225, 62, 40);
	// vars->color_bg[1] = create_hsv(166, 38, 100);

	/* init sphere objects, use malloc */
	vars->count_sph = 4;
	malloc_sph_ptr(&vars->sph, vars->count_sph);
	vars->sph[0] = new_sphere(new_vector3d(0, 0, -1.2), 0.5, \
new_vector3d(0.1, 0.2, 0.5), DIFFUSE); //center
	vars->sph[1] = new_sphere(new_vector3d(0, -100.5, -1), 100, \
new_vector3d(0.8, 0.8, 0), DIFFUSE); //ground
	vars->sph[2] = new_sphere(new_vector3d(-1, 0, -1), 0.5, \
new_vector3d(0.8, 0.8, 0.8), METAL); //left
	vars->sph[3] = new_sphere(new_vector3d(1, 0, -1), 0.5, \
new_vector3d(0.8, 0.6, 0.2), METAL); //right

	my_create_image(vars, &vars->img);
}
