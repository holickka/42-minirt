/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:47:55 by hsim              #+#    #+#             */
/*   Updated: 2025/05/05 18:12:06 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * /2.55 here is short form of: /255*100
 * /255->(normalize value to 1), then *100(convert value to 0-100)
 */
static int	get_max_rgb(int *color, char *res)
{
	if (color[R] >= color[G] && color[R] >= color[B])
	{
		*res = 'R';
		return (color[R] / 2.55);
	}
	else if (color[G] >= color[R] && color[G] >= color[B])
	{
		*res = 'G';
		return (color[G] / 2.55);
	}
	else if (color[B] >= color[R] && color[B] >= color[G])
	{
		*res = 'B';
		return (color[B] / 2.55);
	}
	*res = '\0';
	return (ft_perror("🚨 Error in get_max_rgb", 0));
}

/*
 * /2.55 here is short form of: /255*100
 * /255->(normalize value to 1), then *100(convert value to 0-100)
 */
static int	get_min_rgb(int *color)
{
	if (color[R] <= color[G] && color[R] <= color[B])
		return (color[R] / 2.55);
	else if (color[G] <= color[R] && color[G] <= color[B])
		return (color[G] / 2.55);
	else if (color[B] <= color[R] && color[B] <= color[G])
		return (color[B] / 2.55);
	return (ft_perror("🚨 Error in get_min_rgb", 0));
}

/* 
 * gets hue value from rgb hex code
 * uses *60 to get angles in 0-360 deg range
 * single number: 0, 2, 4 represent the hue color segment
 * long explaination refer notes on notion
 */
static int	get_rgb_h(int chroma, int *color, char c)
{
	int	res;

	res = 0;
	if (c != 'R' && c != 'G' && c != 'B')
		return (ft_perror("🚨 Input is not RGB in function get_rgb_h", -1));
	color[R] /= 2.55;
	color[G] /= 2.55;
	color[B] /= 2.55;
	if (chroma == 0)
		res = 0;
	else if (c == 'R')
		res = (((float)(color[G] - color[B]) / chroma) + 0) * 60;
	else if (c == 'G')
		res = (((float)(color[B] - color[R]) / chroma) + 2) * 60;
	else if (c == 'B')
		res = (((float)(color[R] - color[G]) / chroma) + 4) * 60;
	if (res < 0)
		res += 360;
	return (res);
}

/* 
 * convert rgb to hsv values, returns a single hsv pointer
 * uses malloc
 */
static int	*rgb_to_hsv(int rgb)
{
	int		color[3];
	float	min_rgb;
	int		*hsv;
	char	res;

	if (rgb < 0)
		return (NULL);
	hsv = create_hsv(0, 0, 0);
	if (!hsv)
		return (NULL);
	color[R] = (rgb >> 16) & 0xFF;
	color[G] = (rgb >> 8) & 0xFF;
	color[B] = rgb & 0xFF;
	min_rgb = get_min_rgb(color);
	hsv[V] = get_max_rgb(color, &res);
	hsv[S] = ((((float)hsv[V] - min_rgb) / hsv[V]) * 100);
	hsv[H] = get_rgb_h((hsv[V] - min_rgb), color, res);
	return (hsv);
}

/* uses malloc in rgb_to_hsv function */
int	save_rgb_to_hsv(char *color_hex, int **hsv_array, int i)
{
	int		*res;
	int		rgb_value;

	if (!color_hex)
		return (1);
	rgb_value = ft_basetoi("0123456789abcdef", color_hex, 8);
	res = rgb_to_hsv(rgb_value);
	if (!res)
	{
		return (ft_perror("🚨 Error! rgb_value < 0 in save_rgb_to_hsv!", 0));
		free(res);
	}
	if (res[H] < 0 || res[S] < 0 || res[V] < 0)
	{
		ft_printf("🚨 RGB conversion error in save_rgb_to_hsv!,");
		ft_printf("RGB= %s %d\n", color_hex, rgb_value);
		free(res);
		return (0);
	}
	hsv_array[H][i] = res[H];
	hsv_array[S][i] = res[S];
	hsv_array[V][i] = res[V];
	free(res);
	return (1);
}
