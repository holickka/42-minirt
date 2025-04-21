/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:33:14 by hsim              #+#    #+#             */
/*   Updated: 2024/12/27 21:36:59 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

float	ft_square(float num)
{
	return (num * num);
}

/* 
 * Creates a new quaternion,
 * a rotation instruction with degree & axis of rotation
 * q = cos(deg/2) + sin(deg/2)( x + y + z )
 *   = cos(deg/2) + (x * sin(deg/2)) + (y * sin(deg/2)) + (z * sin(deg/2))
 */
t_quat	new_quaternion(t_vector3d axis, float deg)
{
	t_quat	q;
	float	rad;

	rad = (deg * M_PI) / 180;
	q.scalar = cos(rad / 2);
	q.vector = multiply_vector_scalar(axis, sin(rad / 2));
	return (q);
}

/*
 * Conjugate Quaternion
 * reverses sign of quaternion vectors to negative
 */
t_quat	conjugate_quaternion(t_quat q1)
{
	t_quat	result;

	result.scalar = q1.scalar;
	result.vector = multiply_vector_scalar(q1.vector, -1.0);
	return (result);
}

/* 
 * Calculates the length/magnitude/norm of quaternion
 * = sqrt(scalar sq + i sq + j sq + k sq)
 */
float	len_quaternion(t_quat q1)
{
	return (sqrt(ft_square(q1.scalar) + ft_square(q1.vector.x) + \
				ft_square(q1.vector.y) + ft_square(q1.vector.z)));
}

/*
 * Unit Quaternion
 * Normalize the quaternion to length of 1
 * = q / len_quaternion
 */
void	norm_quaternion(t_quat *q1)
{
	float	qlength;

	qlength = len_quaternion(*q1);
	q1->scalar /= qlength;
	q1->vector = multiply_vector_scalar(q1->vector, 1.0 / qlength);
}
