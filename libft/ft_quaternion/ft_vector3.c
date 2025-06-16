/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:20:52 by hsim              #+#    #+#             */
/*   Updated: 2025/06/15 12:24:18 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

/* 
 * Multiply vector with scalar 
 * q = cos(deg/2) + sin(deg/2)( x + y + z )
 */
t_vector3d	multiply_vec_scalar(t_vector3d a, float s)
{
	t_vector3d	result;

	result.x = a.x * s;
	result.y = a.y * s;
	result.z = a.z * s;
	return (result);
}

/* Divide vector with scalar */
t_vector3d	div_vector_scalar(t_vector3d a, float s)
{
	t_vector3d	result;

	result.x = a.x / s;
	result.y = a.y / s;
	result.z = a.z / s;
	return (result);
}

/* Subtract vector with scalar */
t_vector3d	subtract_vector_scalar(t_vector3d a, float s)
{
	t_vector3d	result;

	result.x = a.x - s;
	result.y = a.y - s;
	result.z = a.z - s;
	return (result);
}
