/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:37:14 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 18:53:45 by hsim             ###   ########.fr       */
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
}	t_vec3;

typedef struct s_quaternion
{
	float		scalar;
	t_vec3	vector;
}	t_quat;

t_vec3	new_vector3d(float x, float y, float z);
float		len_vector3d(t_vec3 vector);
t_vec3	unit_vector3d(t_vec3 vector);
t_vec3	mult_vec_scalar(t_vec3 a, float s);
t_vec3	subtract_vector_scalar(t_vec3 a, float s);
t_vec3	div_vec_scalar(t_vec3 a, float s);

t_vec3	add_vec(t_vec3 a, t_vec3 b);
t_vec3	subtract_vec(t_vec3 a, t_vec3 b);

float		scalar_product(t_vec3 a, t_vec3 b);
t_vec3	multiply_vec(t_vec3 a, t_vec3 b);
t_vec3	cross_product3d(t_vec3 a, t_vec3 b);
t_vec3	cross_product_quaternion(t_quat a, t_quat b);

/* 
 * Quaternion Library
 */

float		ft_square(float num);
float		radian(float deg);

t_quat		new_quaternion(t_vec3 set, float deg);
t_quat		conjugate_quaternion(t_quat q1);
float		len_quaternion(t_quat q1);
void		norm_quaternion(t_quat *q1);
t_quat		quaternion_multiply(t_quat q1, t_quat q2);
t_vec3	quaternion_rotate(t_quat q1, t_vec3 initpoint);
t_vec3	quaternion_rotate_adv( \
t_quat x, t_quat y, t_quat z, t_vec3 initpoint);

#endif