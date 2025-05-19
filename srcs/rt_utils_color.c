/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 08:00:56 by hsim              #+#    #+#             */
/*   Updated: 2025/05/06 17:53:11 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * input values ranges frm 0 to 255
 * returns a rgb value
 */
int	create_rgb(int r_value, int g_value, int b_value)
{
	// /*debug*/printf("create_rgb:%d %d %d\n", r_value, g_value, b_value);
	return (r_value << 16 | g_value << 8 | b_value);
}

/*
 * h_value = degree of hue from 0 to 360deg, dont put 1deg
 * s_value = 0 to 1
 * v_value = 0 to 1
 * this function uses malloc
 */
int	*create_hsv(int h_value, int s_value, int v_value)
{
	int	*new_hsv;

	if (h_value < 0 || h_value > 360 || s_value < 0 || s_value > 100 \
		|| v_value < 0 || v_value > 100)
	{
		ft_printf("🚨 current HSV=%d %d %d\n", h_value, s_value, v_value);
		ft_printf("🚨 HSV values must be between 360deg and 0-100");
		return (NULL);
	}
	new_hsv = (int *)malloc(3 * sizeof(int));
	if (!new_hsv)
	{
		ft_printf("🚨 Memory allocation for HSV failed");
		return (NULL);
	}
	new_hsv[H] = h_value;
	new_hsv[S] = s_value;
	new_hsv[V] = v_value;
	return (new_hsv);
}

static void	swap_value(int *num1, int *num2)
{
	int	tmp;
	int	x;

	if (!num1 || !num2)
		return ;
	x = -1;
	while (x++ < 2)
	{
		tmp = num1[x];
		num1[x] = num2[x];
		num2[x] = tmp;
	}
}

static void	copy_hsv(int *tmp1, int *hsv1, int *tmp2, int *hsv2)
{
	if ((!tmp1 && !hsv1) || (!tmp2 && !hsv2))
		return ;
	tmp1[H] = hsv1[H];
	tmp1[S] = hsv1[S];
	tmp1[V] = hsv1[V];
	tmp2[H] = hsv2[H];
	tmp2[S] = hsv2[S];
	tmp2[V] = hsv2[V];
}

static void	lerp_h(int tmp_hsv[2][3], int *new_hsv, int diff, float t)
{
	if (diff > 180)
		tmp_hsv[0][H] += 360;
	new_hsv[H] = (tmp_hsv[0][H] + (t * (tmp_hsv[1][H] - tmp_hsv[0][H])));
	if (diff > 180)
		new_hsv[H] = (new_hsv[H] % 360);
}

/* 
 * hsv values has to between 0 and 1, malloc involved, pls free()
 * t = ((dy_or_dx - current.point) / dy_or_dx )
 *   = 1 - (current.point / dy_or_dx)
 *   = 1 - (400/800.0) must add .0 convert to float
 * return rgb value after lerp
 */
int	lerp_hsv(int *hsv1, int *hsv2, float t)
{
	int		*new_hsv;
	int		diff;
	int		new_rgb;
	int		tmp_hsv[2][3];

	copy_hsv(tmp_hsv[0], hsv1, tmp_hsv[1], hsv2);
	if (t < 0)
		t *= -1;
	new_hsv = create_hsv(0, 0, 0);
	if (!new_hsv)
		return (0);
	diff = abs(tmp_hsv[1][H] - tmp_hsv[0][H]);
	if (tmp_hsv[0][H] > tmp_hsv[1][H])
	{
		swap_value(tmp_hsv[0], tmp_hsv[1]);
		t = 1.0 - t;
	}
	lerp_h(tmp_hsv, new_hsv, diff, t);
	new_hsv[S] = (tmp_hsv[0][S] + (t * (tmp_hsv[1][S] - tmp_hsv[0][S])));
	new_hsv[V] = (tmp_hsv[0][V] + (t * (tmp_hsv[1][V] - tmp_hsv[0][V])));
	new_rgb = hsv_to_rgb(new_hsv);
	free(new_hsv);
	return (new_rgb);
}
