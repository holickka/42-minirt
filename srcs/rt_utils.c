/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:18:14 by hsim              #+#    #+#             */
/*   Updated: 2025/05/22 20:40:33 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* checks if all vector values is near to zero */
bool	is_near_zero(t_vector3d vec)
{
	int	res[3];

	res[X] = fabs(vec.x);
	res[Y] = fabs(vec.y);
	res[Z] = fabs(vec.z);
	return ((res[X] < 0.001f) && (res[Y] < 0.001f) && (res[Z] < 0.001f));
}
