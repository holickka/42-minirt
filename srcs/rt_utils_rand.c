/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_rand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:15:24 by hsim              #+#    #+#             */
/*   Updated: 2025/05/20 18:11:11 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * returns a random seed using LCG (linear congruential generator)
 * new_seed = (a * seed + c) mod m
 * 
 * values of a, c, m derived from article below:
 * https://en.wikipedia.org/wiki/Linear_congruential_generator
 */
static unsigned int	lcg(unsigned int *seed)
{
	unsigned int	a;
	unsigned int	c;
	unsigned int	m;

	a = 1664525;
	c = 1013904223;
	m = 0xFFFFFFFF;
	*seed = ((a * (*seed)) + c) % m;
	return (*seed);
}

/*
 * enter a seed number,
 * returns a random float number, based on lcg algorithm
 */
float	rand_lcg(unsigned int *seed)
{
	return ((float)lcg(seed) / 0xFFFFFFFF);
}

/* returns a random float number within a range, based on lcg algorithm */
float	rand_lcg_range(unsigned int *seed, float min, float max)
{
	return (min + ((max - min) * (float)lcg(seed) / 0xFFFFFFFF));
}

t_vector3d	rand_vec(unsigned int *seed)
{
	t_vector3d	res;

	res = new_vector3d(rand_lcg(seed), rand_lcg(seed), rand_lcg(seed));
	return (res);
}

/*
 * generate & returns a random unit vector that lies within the unit sphere
 * len_sq <= 1 is to make sure the vector is within sphere (with unit len of 1)
 */
t_vector3d	norm_rand_vec(unsigned int *seed)//, t_vector3d surf_norm)
{
	t_vector3d	res;
	float		len_sq;

	res = rand_vec_range(seed, -1, 1);
	// /*debug*/printf("gen: %f %f %f\n", res.x, res.y, res.z);
	len_sq = (res.x * res.x) + \
(res.y * res.y) + \
(res.z * res.z);
	if (len_sq > 0.00001f && len_sq <= 1)
	{
		len_sq = sqrt(len_sq);
		return (div_vector_scalar(res, len_sq));
	}
	return (new_vector3d(-2, -2, -2));
}

/* returns a random vector that lies on sphere surface */
t_vector3d	rand_on_hemisphere(unsigned int *seed, t_vector3d surf_norm)
{
	t_vector3d	vec;

	vec = new_vector3d(-2, -2, -2);
	while (vec.x == -2)
		vec = norm_rand_vec(seed);
	// /*debug*/printf("rand_on_h:%f %f %f\n", vec.x, vec.y, vec.z);
	if (scalar_product(vec, surf_norm) <= 0)
		return (multiply_vector_scalar(vec, -1));
	// /*debug*/printf("rand_on_h:dot: %f\n", scalar_product(vec, surf_norm));
	return (vec);
}

t_vector3d	rand_vec_range(unsigned int *seed, float min, float max)
{
	t_vector3d	res;

	res = new_vector3d(rand_lcg_range(seed, min, max), \
rand_lcg_range(seed, min, max), \
rand_lcg_range(seed, min, max));
	return (res);
}


