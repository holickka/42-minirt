/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:36:20 by hsim              #+#    #+#             */
/*   Updated: 2025/05/20 15:03:24 by hsim             ###   ########.fr       */
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

/* Normalize vector into unit vector */
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

/* Add vector + vector */
t_vector3d	add_vector(t_vector3d a, t_vector3d b)
{
	t_vector3d	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

/* Subtract vector + vector */
t_vector3d	subtract_vector(t_vector3d a, t_vector3d b)
{
	t_vector3d	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}
