/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:20 by hsim              #+#    #+#             */
/*   Updated: 2024/12/27 16:57:31 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/* Creates new vector from given values */
t_vector3d	new_vector3d(float x, float y, float z)
{
	t_vector3d	newvector;

	newvector.x = x;
	newvector.y = y;
	newvector.z = z;
	return (newvector);
}

/* Calculates length of a vector */
float	len_vector3d(t_vector3d vector)
{
	return (sqrt((vector.x * vector.x) + \
				(vector.y * vector.y) + \
				(vector.z * vector.z)));
}

/* Normalize vector */
t_vector3d	norm_vector3d(t_vector3d vector)
{
	float	length;

	length = len_vector3d(vector);
	if (length >= 0.00001f)
		return (new_vector3d(vector.x / length, \
							vector.y / length, \
							vector.z / length));
	return (vector);
}

/* 
 * Multiply vector with scalar 
 * q = cos(deg/2) + sin(deg/2)( x + y + z )
 */
t_vector3d	multiply_vector_scalar(t_vector3d a, float s)
{
	t_vector3d	result;

	result.x = a.x * s;
	result.y = a.y * s;
	result.z = a.z * s;
	return (result);
}

/* Add vector + vector */
t_vector3d	add_vector(t_vector3d a, t_vector3d b)
{
	t_vector3d	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}
