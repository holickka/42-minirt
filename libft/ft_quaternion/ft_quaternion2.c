/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:55:02 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 18:53:38 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
/* 
 * Quaternion Multiplication
 * Multiply q1 * q2
 * Not commutative !!
 * a1a2 - x1x2 - y1y2 - z1z2
 * + (a1x2 + x1a2 + y1z2 - z1y2)i
 * + (a1y2 - x1z2 + y1a2 + z1x2)j
 * + (a1z2 + x1y2 - y1x2 + z1a2)k
 */
t_quat	quaternion_multiply(t_quat q1, t_quat q2)
{
	t_quat	result;

	result.scalar = (q1.scalar * q2.scalar) - \
scalar_product(q1.vector, q2.vector);
	result.vector = cross_product_quaternion(q1, q2);
	return (result);
}

/*
 * Quaternion Rotation
 * in Unit Quaternion, q inverse = conjugate quaternion
 * normalize quaternion, then multiply them
 * new p = q . p . q inverse
 * q1= the rotation quaternion
 */
t_vec3	quaternion_rotate(t_quat q1, t_vec3 initpoint)
{
	t_quat	q2;
	t_quat	qpoint;
	t_quat	result;

	qpoint.scalar = 0.0;
	qpoint.vector = initpoint;
	norm_quaternion(&q1);
	q2 = conjugate_quaternion(q1);
	result = quaternion_multiply(q1, qpoint);
	result = quaternion_multiply(result, q2);
	return (result.vector);
}

/*
 * x = x-axis rotation in quaternion, same follows y & z
 * normally will normalize quaternion before rotation
 * new point = x . y . z . point . x inverse . y inverse . z inverse
 * quaternion multiplication on:
 * left (q2 . q1) = rotation on global axis,
 * right (q1 . q2) = rotation on local axis 
 */
t_vec3	quaternion_rotate_adv(t_quat x, t_quat y, t_quat z, \
t_vec3 initpoint)
{
	t_quat	qpoint;
	t_quat	result;
	t_quat	conjugate_x;
	t_quat	conjugate_y;
	t_quat	conjugate_z;

	qpoint.scalar = 0.0;
	qpoint.vector = initpoint;
	conjugate_x = conjugate_quaternion(x);
	conjugate_y = conjugate_quaternion(y);
	conjugate_z = conjugate_quaternion(z);
	result = quaternion_multiply(z, y);
	result = quaternion_multiply(result, x);
	result = quaternion_multiply(result, qpoint);
	result = quaternion_multiply(result, conjugate_z);
	result = quaternion_multiply(result, conjugate_y);
	result = quaternion_multiply(result, conjugate_x);
	return (result.vector);
}
