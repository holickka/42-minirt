/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:56:34 by hsim              #+#    #+#             */
/*   Updated: 2024/12/27 22:37:27 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
 * Calculates scalar product of given vector
 */
float	scalar_product(t_vector3d a, t_vector3d b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

/*
 * Cross product of a cross b
 * Returns a new vector
 */
t_vector3d	cross_product3d(t_vector3d a, t_vector3d b)
{
	t_vector3d	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

t_vector3d	cross_product_quaternion(t_quat a, t_quat b)
{
	t_vector3d	result;

	result.x = (a.scalar * b.vector.x) + (a.vector.x * b.scalar) + \
				(a.vector.y * b.vector.z) - (a.vector.z * b.vector.y);
	result.y = (a.scalar * b.vector.y) + (a.vector.y * b.scalar) + \
				(a.vector.z * b.vector.x) - (a.vector.x * b.vector.z);
	result.z = (a.scalar * b.vector.z) + (a.vector.z * b.scalar) + \
				(a.vector.x * b.vector.y) - (a.vector.y * b.vector.x);
	return (result);
}
