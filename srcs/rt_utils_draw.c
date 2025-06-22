/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:21:10 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 15:12:11 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * Template function from mlx documentation
 * Places pixels on image
 *
 * Reference:
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#writing-pixels-to-a-image
 */
void	my_mlx_pixel_put(t_vars vars, int x, int y, int color)
{
	int		offset;
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	offset = ((y * vars.img.line_length) + (x * (vars.img.bits_per_pixel / 8)));
	dst = vars.img.addr + offset;
	*(unsigned int *)dst = color;
}

/* Renders the image black color*/
void	clear_image(t_vars vars, int win_width, int win_height, int color)
{
	int	tmp;

	while (win_height >= 0)
	{
		tmp = win_width;
		while (tmp >= 0)
			my_mlx_pixel_put(vars, tmp--, win_height, color);
		win_height--;
	}
}

/* Create image container to start draw */
void	my_create_image(t_vars *vars, t_imgdata *img)
{
	img->image = mlx_new_image(vars->mlxconnect, WIN_WIDTH, WIN_HEIGHT);
	if (!img->image)
		ft_perror("🚨 Error in creating main image!", 0);
	img->addr = mlx_get_data_addr(img->image, \
&img->bits_per_pixel, \
&img->line_length, \
&img->endian);
}

/*
 * viewport_00 = center of pixel 00 in viewport
 * viewport_d = dydx or dudv of viewport
 */
static void	ft_draw(t_vars vars, t_vector3d viewport_00, t_vector3d viewport_d[2])
{
	int			x;
	int			y;
	int			color;
	t_vector3d	target;

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
			// target = add_vec(viewport_00, add_vec(\
// mult_vec_scalar(viewport_d[X], x), mult_vec_scalar(viewport_d[Y], y)));
			// target.x = viewport_00.x + (x * viewport_d[X].x); //short
			target.x = viewport_00.x + (x * viewport_d[X].x) + (y * viewport_d[Y].x);

// = viewport_00.x + (x * d_x) + (offset.x * d_x)

// x = viewport_00.x + (x * dx.x)  |->  + (offset.x * dx.x)
//                   + (y * dy.x)  |->  + (offset.y * dy.x)


			// // /*debug*/printf("ft_draw:target:%f %f\n", target.x, target.y);
			// vars.ray.vector = subtract_vector(target, vars.cam_orig);
			// /*debug*/printf("ft_draw:tar:%f %f %f\n", target.x, target.y, target.z);
			// // /*debug*/printf("ft_draw:vp:%f %f %f\n", viewport_00.x, viewport_00.y, viewport_00.z);
			// // /*debug*/printf("ft_draw:cam:%f %f %f\n", vars.ray.vector.x, vars.ray.vector.y,  vars.ray.vector.z);
			// color = ray_color(vars, vars.ray);
			color = sample_pixels(vars, target, viewport_d, x);
			my_mlx_pixel_put(vars, x, y, color);
		}
	}
}

/* get value of viewport_uv and save to t_vector3d *viewport_u & t_vector3d *viewport_v*/
void	get_viewport_uv(t_vars *vars, t_vector3d *viewport_u, t_vector3d *viewport_v, t_vector3d *cam_w)
{
	float		h;
	float		defoc_radius;
	float		viewport[2];
	t_vector3d	cam[2];
	(void)	cam_w;

	h = tan(vars->vfov / 2);
	viewport[Y] = 2 * h * vars->focus_dist;
	viewport[X] = (viewport[Y] * WIN_WIDTH) / WIN_HEIGHT;
	/*debug*/printf("h:%f, viewport: %f %f\n", h, viewport[X], viewport[Y]);

	*cam_w = unit_vector3d(subtract_vec(vars->cam_orig, vars->cam_lookat));
	cam[X] = unit_vector3d(cross_product3d(vars->vup, *cam_w));
	cam[Y] = mult_vec_scalar(cross_product3d(*cam_w, cam[X]), -1); // -v
	*viewport_u = mult_vec_scalar(cam[X], viewport[X]);
	*viewport_v = mult_vec_scalar(cam[Y], viewport[Y]);
	/*debug*/printf("cam_w: %f %f %f\n", (*cam_w).x, (*cam_w).y, (*cam_w).z);
	/*debug*/printf("cam_u: %f %f %f\n", cam[X].x, cam[X].y, cam[X].z);
	/*debug*/printf("cam_v: %f %f %f\n", cam[Y].x, cam[Y].y, cam[Y].z);

	defoc_radius = vars->focus_dist * tan(vars->defoc_ang / 2);
	vars->defoc_disk[X] = mult_vec_scalar(cam[X], defoc_radius);
	vars->defoc_disk[Y] = mult_vec_scalar(cam[Y], defoc_radius);

	// *viewport_u = new_vector3d(viewport[X], 0, 0);
	// *viewport_v = new_vector3d(0, -viewport[Y], 0);
	/*debug*/printf("vp_uv in: %f %f %f, %f %f %f\n", (*viewport_u).x, (*viewport_u).y, (*viewport_u).z, (*viewport_v).x, (*viewport_v).y, (*viewport_v).z);
}

/*
 * viewport_00 = center of pixel 00 in viewport
 * viewport_d = dydx or dudv of viewport
 */
void	my_render_image(t_vars *vars)
{
	t_vector3d	viewport_d[2];
	t_vector3d	vp[2];
	t_vector3d	cam_w;
	t_vector3d	viewport_00_loc;
	t_vector3d	viewport_top_left;

	get_viewport_uv(vars, &vp[X], &vp[Y], &cam_w);
	viewport_d[X] = div_vec_scalar(vp[X], WIN_WIDTH);
	viewport_d[Y] = div_vec_scalar(vp[Y], WIN_HEIGHT);
	// viewport_upper_left = center - (focal_length * w) - viewport_u/2 - viewport_v/2;
	// viewport_top_left = subtract_vec(vars.cam_orig, mult_vec_scalar(cam_w, vars.focal_len));
	// viewport_top_left = subtract_vec(viewport_top_left, div_vec_scalar(vp[X], 2));
	// viewport_top_left = subtract_vec(viewport_top_left, div_vec_scalar(vp[Y], 2));

	/* old v */

	viewport_top_left = subtract_vec(vars->cam_orig, div_vec_scalar(cam_w, vars->focus_dist));
	viewport_top_left = subtract_vec(viewport_top_left, div_vec_scalar(vp[X], 2));
	viewport_top_left = subtract_vec(viewport_top_left, div_vec_scalar(vp[Y], 2));

	viewport_00_loc = add_vec(viewport_top_left, \
div_vec_scalar(add_vec(viewport_d[X], viewport_d[Y]), 2));

	// /*debug*/printf("vp_uv out: %f %f %f, %f %f %f\n", vp[X].x, vp[X].y, vp[X].z, vp[Y].x, vp[Y].y, vp[Y].z);
	/*debug*/printf("viewport_x: %f %f %f\n", vp[X].x, vp[X].y, vp[X].z);
	/*debug*/printf("viewport_y: %f %f %f\n", vp[Y].x, vp[Y].y, vp[Y].z);
	/*debug*/printf("viewport_dx: %f %f %f\n", viewport_d[X].x, viewport_d[X].y, viewport_d[X].z);
	/*debug*/printf("viewport_dy: %f %f %f\n", viewport_d[Y].x, viewport_d[Y].y, viewport_d[Y].z);
	/*debug*/printf("top_left: %f %f %f\n", viewport_top_left.x, viewport_top_left.y, viewport_top_left.z);
	/*debug*/printf("00_loc: %f %f %f\n", viewport_00_loc.x, viewport_00_loc.y, viewport_00_loc.z);


/* *********************************************************** */


	// clear_img & put to window (maybe no need)
	clear_image(*vars, WIN_WIDTH, WIN_HEIGHT, 0x000000);
	mlx_put_image_to_window(vars->mlxconnect, vars->mlxwindow, \
vars->img.image, 0, 0);

	//draw
	ft_draw(*vars, viewport_00_loc, viewport_d);
	//push draw result to window
	mlx_put_image_to_window(vars->mlxconnect, vars->mlxwindow, \
vars->img.image, 0, 0);
}
