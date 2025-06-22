/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_draw2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:21:10 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 18:54:55 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * child function in get_viewport_coords
 * get value of viewport_uv and save to
 * t_vector3d *viewport_u & *viewport_v
 */
static void	get_viewport_uv(t_vars *vars, t_vec3 *viewport_u, \
t_vec3 *viewport_v, t_vec3 *cam_w)
{
	float		h;
	float		defoc_radius;
	float		viewport[2];
	t_vec3	cam[2];

	h = tan(vars->vfov / 2);
	viewport[H] = 2 * h * vars->focus_dist;
	viewport[W] = (viewport[H] * WIN_WIDTH) / WIN_HEIGHT;
	// /*debug*/printf("h:%f, viewport: %f %f\n", h, viewport[X], viewport[Y]);

	*cam_w = unit_vector3d(subtract_vec(vars->cam_orig, vars->cam_lookat));
	cam[X] = unit_vector3d(cross_product3d(vars->vup, *cam_w));
	cam[Y] = mult_vec_scalar(cross_product3d(*cam_w, cam[X]), -1); // -v
	*viewport_u = mult_vec_scalar(cam[X], viewport[W]);
	*viewport_v = mult_vec_scalar(cam[Y], viewport[H]);
	// /*debug*/printf("cam_w: %f %f %f\n", (*cam_w).x, (*cam_w).y, (*cam_w).z);
	// /*debug*/printf("cam_u: %f %f %f\n", cam[X].x, cam[X].y, cam[X].z);
	// /*debug*/printf("cam_v: %f %f %f\n", cam[Y].x, cam[Y].y, cam[Y].z);

	defoc_radius = vars->focus_dist * tan(vars->defoc_ang / 2);
	vars->defoc_disk[X] = mult_vec_scalar(cam[X], defoc_radius);
	vars->defoc_disk[Y] = mult_vec_scalar(cam[Y], defoc_radius);

	// *viewport_u = new_vector3d(viewport[X], 0, 0);
	// *viewport_v = new_vector3d(0, -viewport[Y], 0);
	/*debug*/printf("vp_uv in: %f %f %f, %f %f %f\n", (*viewport_u).x, (*viewport_u).y, (*viewport_u).z, (*viewport_v).x, (*viewport_v).y, (*viewport_v).z);
}

/*
 * child function in my_render_image
 * get starting values of viewport (viewport top_left)
 * & center of top_left_pixel (viewport_00_loc)
 */
static void	get_viewport_coords(t_vars *vars, t_vec3 *vp_00_loc, \
t_vec3 *vp_top_left, t_vec3 vp_d[2])
{
	t_vec3	vp[2];
	t_vec3	cam_w;

	get_viewport_uv(vars, &vp[X], &vp[Y], &cam_w);
	vp_d[X] = div_vec_scalar(vp[X], WIN_WIDTH);
	vp_d[Y] = div_vec_scalar(vp[Y], WIN_HEIGHT);

	*vp_top_left = subtract_vec(vars->cam_orig, \
mult_vec_scalar(cam_w, vars->focus_dist));
	*vp_top_left = subtract_vec(*vp_top_left, div_vec_scalar(vp[X], 2));
	*vp_top_left = subtract_vec(*vp_top_left, div_vec_scalar(vp[Y], 2));

	*vp_00_loc = add_vec(*vp_top_left, \
div_vec_scalar(add_vec(vp_d[X], vp_d[Y]), 2));

	/*debug*/debug_print_vec("viewport_x:", vp[X]);
	/*debug*/debug_print_vec("viewport_y:", vp[Y]);
	/*debug*/debug_print_vec("viewport_dx:", vp_d[X]);
	/*debug*/debug_print_vec("viewport_dy:", vp_d[Y]);
	/*debug*/debug_print_vec("00_loc:", *vp_00_loc);
}

/*
 * child function in my_render_image
 * viewport_00 = center of pixel 00 in viewport
 * viewport_d = dydx or dudv of viewport
 */
static void	ft_draw(t_vars vars, t_vec3 viewport_00, t_vec3 viewport_d[2])
{
	int		x;
	int		y;
	int		color;
	t_vec3	target;

	x = -1;
	y = -1;
	target = viewport_00;
	// target.z = viewport_00.z + (x * viewport_d[X].z) + (y * viewport_d[Y].z);
	while (++y < WIN_HEIGHT)
	{
		x = 0;
		target.y = viewport_00.y + (x * viewport_d[X].y) + (y * viewport_d[Y].y);
		// target.y = viewport_00.y + (y * viewport_d[Y].y);
		while (++x < WIN_WIDTH)
		{
			// target.x = viewport_00.x + (x * viewport_d[X].x); //short
			target.x = viewport_00.x + (x * viewport_d[X].x) + (y * viewport_d[Y].x);
// x = viewport_00.x + (x * dx.x)  |->  + (offset.x * dx.x)
//                   + (y * dy.x)  |->  + (offset.y * dy.x)
			color = sample_pixels(vars, target, viewport_d, x);
			my_mlx_pixel_put(vars, x, y, color);
		}
	}
}

/*
 * vp_00 = center of pixel 00 in viewport
 * vp_d = dydx or dudv of viewport
 */
void	my_render_image(t_vars *vars)
{
	t_vec3	vp_d[2];
	t_vec3	vp_00_loc;
	t_vec3	vp_top_left;

	//clear before draw
	clear_image(*vars, WIN_WIDTH, WIN_HEIGHT, 0x000000);
	mlx_put_image_to_window(vars->mlxconnect, vars->mlxwindow, \
vars->img.image, 0, 0);
	//draw
	get_viewport_coords(vars, &vp_00_loc, &vp_top_left, vp_d);
	ft_draw(*vars, vp_00_loc, vp_d);
	//push draw result to window
	mlx_put_image_to_window(vars->mlxconnect, vars->mlxwindow, \
vars->img.image, 0, 0);
}
