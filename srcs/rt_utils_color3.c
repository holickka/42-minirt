/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:11:59 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 15:11:59 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * input values ranges frm 0 to 255
 * returns a rgb value
 */
int	create_rgb(int r_value, int g_value, int b_value)
{
	return (r_value << 16 | g_value << 8 | b_value);
}

/* variation of rgb */
t_vector3d	lerp_rgb(t_vector3d c1, t_vector3d c2, float t)
{
	t_vector3d	color;

	color = add_vec(mult_vec_scalar(c1, (1 - t)), \
mult_vec_scalar(c2, t));
	return (color);
}
