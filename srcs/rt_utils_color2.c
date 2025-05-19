/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:56:47 by hsim              #+#    #+#             */
/*   Updated: 2025/05/05 17:25:04 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*Converts single rgb values to int for bresenhams*/
static int	rgb_to_hex(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	r = r << 16;
	g = g << 8;
	return (r + g + b);
}

/*
 * get rgb values from given hsv
 */
static void	get_rgb(int *new_hsv, int diff_h_seg_max_seg, int **ptr, int *min)
{
	float	chrome;
	float	min_float;

	chrome = ((float)new_hsv[V] / 100 * (float)new_hsv[S] / 100);
	min_float = ((float)new_hsv[V] / 100 - chrome);
	if (min == ptr[BRG])
		*ptr[GBR] = (((min_float + (((float)diff_h_seg_max_seg / 60) * chrome)) \
					* 255) + ROUND_UP);
	else if (min == ptr[GBR])
	{
		*ptr[BRG] = (((min_float - (((float)diff_h_seg_max_seg / 60) * chrome)) \
					* 255) + ROUND_UP);
	}
	*ptr[RGB] = ((((float)new_hsv[V] / 100) * 255) + ROUND_UP);
	*min = ((min_float * 255) + ROUND_UP);
}

/*
 * how to use max_r_g_b, g_b_r and b_r_g:
 * eg if max_r, following val in column g_b_r = g, and b_r_g = b
 * max_rgb, g_b_r, b_r_g has to be addresses '&'
 */
static void	get_hsv_polarity(int *new_hsv, int h_seg, int max_seg, int **ptr)
{
	int	diff;

	diff = h_seg - max_seg;
	if (diff < 0)
		get_rgb(new_hsv, diff, ptr, ptr[GBR]);
	else if (diff >= 0)
		get_rgb(new_hsv, diff, ptr, ptr[BRG]);
}

static void	assign_rgb_container(int **container, \
								int *max_r_g_b, int *g_b_r, int *b_r_g)
{
	if (!container || !max_r_g_b || !g_b_r || !b_r_g)
		return ;
	container[RGB] = max_r_g_b;
	container[GBR] = g_b_r;
	container[BRG] = b_r_g;
}

/*
 * child function in lerp_hsv
 * converts the lerp_hsv to rgb values, int version
 * the range numbers representing h angles in segment R,G,&B
 */
int	hsv_to_rgb(int *new_hsv)
{
	int	h_segment;
	int	new_rgb[3];
	int	*ptr[3];

	h_segment = new_hsv[H];
	if (h_segment > 300)
		h_segment -= 360;
	if (h_segment >= -60 && h_segment <= 60)
	{
		assign_rgb_container(ptr, &new_rgb[R], &new_rgb[G], &new_rgb[B]);
		get_hsv_polarity(new_hsv, h_segment, 0, ptr);
	}
	else if (h_segment > 60 && h_segment <= 180)
	{
		assign_rgb_container(ptr, &new_rgb[G], &new_rgb[B], &new_rgb[R]);
		get_hsv_polarity(new_hsv, h_segment, 120, ptr);
	}
	else if (h_segment > 180 && h_segment <= 300)
	{
		assign_rgb_container(ptr, &new_rgb[B], &new_rgb[R], &new_rgb[G]);
		get_hsv_polarity(new_hsv, h_segment, 240, ptr);
	}
	return (rgb_to_hex(new_rgb[R], new_rgb[G], new_rgb[B]));
}
