/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:56:34 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 18:53:38 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/*
 * multiply 2 vectors together, return single number
 * Calculates scalar product / dot product of given vectors
 */
float	scalar_product(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

/*
 * officially known as hadamart product,
 * returns a.x * b.x,  a.y * b.y,  a.z * b.z
 */
t_vec3	multiply_vec(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

/*
 * Cross product of a cross b
 * Returns a new vector
 */
t_vec3	cross_product3d(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

t_vec3	cross_product_quaternion(t_quat a, t_quat b)
{
	t_vec3	result;

	result.x = (a.scalar * b.vector.x) + (a.vector.x * b.scalar) + \
(a.vector.y * b.vector.z) - (a.vector.z * b.vector.y);
	result.y = (a.scalar * b.vector.y) + (a.vector.y * b.scalar) + \
(a.vector.z * b.vector.x) - (a.vector.x * b.vector.z);
	result.z = (a.scalar * b.vector.z) + (a.vector.z * b.scalar) + \
(a.vector.x * b.vector.y) - (a.vector.y * b.vector.x);
	return (result);
}
