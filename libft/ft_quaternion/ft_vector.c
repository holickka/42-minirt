/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:20 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 18:53:38 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/* Creates new vector from given values */
t_vec3	new_vector3d(float x, float y, float z)
{
	t_vec3	newvector;

	newvector.x = x;
	newvector.y = y;
	newvector.z = z;
	return (newvector);
}

/* Calculates length of a vector, returns sqrt(x^2 + y^2 + z^2) */
float	len_vector3d(t_vec3 vector)
{
	return (sqrt((vector.x * vector.x) + \
(vector.y * vector.y) + \
(vector.z * vector.z)));
}

/* Normalize vector into unit vector */
t_vec3	unit_vector3d(t_vec3 vector)
{
	float	len;

	len = len_vector3d(vector);
	if (len >= 0.00001f)
		return (new_vector3d(vector.x / len, \
vector.y / len, \
vector.z / len));
	return (new_vector3d(0, 0, 0));
}

/* Add vector + vector */
t_vec3	add_vec(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

/* return vector a minus vector b */
t_vec3	subtract_vec(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}
