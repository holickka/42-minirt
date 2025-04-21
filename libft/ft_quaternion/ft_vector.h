/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:37:14 by hsim              #+#    #+#             */
/*   Updated: 2024/12/27 21:37:19 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# include <stdarg.h>
# include <math.h>

/*
 * Vector Library 
 */
typedef struct s_vector3d
{
	float	x;
	float	y;
	float	z;
}	t_vector3d;

typedef struct s_quaternion
{
	float		scalar;
	t_vector3d	vector;
}	t_quat;

t_vector3d	new_vector3d(float x, float y, float z);
float		len_vector3d(t_vector3d vector);
t_vector3d	norm_vector3d(t_vector3d vector);
t_vector3d	multiply_vector_scalar(t_vector3d a, float s);
t_vector3d	add_vector(t_vector3d a, t_vector3d b);
float		scalar_product(t_vector3d a, t_vector3d b);
t_vector3d	cross_product3d(t_vector3d a, t_vector3d b);
t_vector3d	cross_product_quaternion(t_quat a, t_quat b);

/* 
 * Quaternion Library
 */

t_quat		new_quaternion(t_vector3d set, float deg);
float		ft_square(float num);
t_quat		conjugate_quaternion(t_quat q1);
float		len_quaternion(t_quat q1);
void		norm_quaternion(t_quat *q1);
t_quat		quaternion_multiply(t_quat q1, t_quat q2);
t_vector3d	quaternion_rotate(t_quat q1, t_vector3d initpoint);
t_vector3d	quaternion_rotate_adv(t_quat x, t_quat y, t_quat z, \
									t_vector3d initpoint);

#endif