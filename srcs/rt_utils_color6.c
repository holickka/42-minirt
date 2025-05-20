/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_color6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:35:46 by hsim              #+#    #+#             */
/*   Updated: 2025/05/20 13:24:05 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* splits color into single r, g, b channel */
t_vector3d	split_rgb(int color)
{
	t_vector3d	res;

	res.x = (color >> 16) & 0xFF;
	res.y = (color >> 8) & 0xFF;
	res.z = color & 0xFF;
	return (res);
}
