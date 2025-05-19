/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:21:10 by hsim              #+#    #+#             */
/*   Updated: 2025/05/19 18:45:20 by hsim             ###   ########.fr       */
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
static void	ft_draw(t_vars vars, t_vector3d viewport_00, t_vector3d viewport_d)
{
	int			x;
	int			y;
	int			color;
	t_vector3d	target;

	x = -1;
	y = -1;
	// target = new_vector3d(0, 0, viewport_00.z);
	target = viewport_00;
	while (++y < WIN_HEIGHT)
	{
		x = 0;
		target.y = viewport_00.y + (y * viewport_d.y);
		while (++x < WIN_WIDTH)
		{
			target.x = viewport_00.x + (x * viewport_d.x);
			// /*debug*/printf("ft_draw:target:%f %f\n", target.x, target.y);
			vars.ray.vector = subtract_vector(target, vars.cam_center);
			/*debug*/printf("ft_draw:tar:%f %f %f\n", target.x, target.y, target.z);
			// /*debug*/printf("ft_draw:vp:%f %f %f\n", viewport_00.x, viewport_00.y, viewport_00.z);
			// /*debug*/printf("ft_draw:cam:%f %f %f\n", vars.ray.vector.x, vars.ray.vector.y,  vars.ray.vector.z);
			color = ray_color(vars, vars.ray);
			my_mlx_pixel_put(vars, x, y, color);
		}
	}
}

/*
 * viewport_00 = center of pixel 00 in viewport
 * viewport_d = dydx or dudv of viewport
 */
void	my_render_image(t_vars vars)
{
	float	viewport[2];
	// t_vector3d	viewport_u = new_vector3d(viewport[X], 0, 0);
	// t_vector3d	viewport_v = new_vector3d(0, -viewport[Y], 0);
	// float	pixel_du = viewport[X] / WIN_WIDTH;
	// float	pixel_dv = -viewport[Y] / WIN_HEIGHT;
	t_vector3d	viewport_d;
	t_vector3d	viewport_top_left;
	t_vector3d	viewport_00_center;

	viewport[Y] = 2;
	viewport[X] = (viewport[Y] * WIN_WIDTH) / WIN_HEIGHT;
	viewport_d = new_vector3d(\
viewport[X] / WIN_WIDTH, -viewport[Y] / WIN_HEIGHT, 0);
	viewport_top_left = subtract_vector(vars.cam_center, \
new_vector3d(viewport[X] / 2, -viewport[Y] / 2, vars.focal_len));
	viewport_00_center = add_vector(viewport_top_left, \
new_vector3d(viewport_d.x / 2, viewport_d.y / 2, 0));

	clear_image(vars, WIN_WIDTH, WIN_HEIGHT, 0x000000); //maybe no need
	mlx_put_image_to_window(vars.mlxconnect, vars.mlxwindow, \
vars.img.image, 0, 0);
	ft_draw(vars, viewport_00_center, viewport_d);
	mlx_put_image_to_window(vars.mlxconnect, vars.mlxwindow, \
vars.img.image, 0, 0);
}
