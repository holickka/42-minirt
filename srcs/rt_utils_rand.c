/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_rand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:15:24 by hsim              #+#    #+#             */
/*   Updated: 2025/06/22 16:49:46 by hsim             ###   ########.fr       */
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
 * returns a random float number between 0 to 1, based on lcg algorithm
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

/* return a random vector with xyz between 0 to 1 */
t_vector3d	rand_vec(unsigned int *seed)
{
	t_vector3d	res;

	res = new_vector3d(rand_lcg(seed), rand_lcg(seed), rand_lcg(seed));
	return (res);
}

/* generate unit_vectors for lens on camera, ranges -1 to 1 */
t_vector3d	rand_unit_disk(unsigned int *seed)
{
	t_vector3d	pt;
	float		len_sq;

	while (1)
	{
		pt = rand_vec_range(seed, -1, 1);
		pt.z = 0;
		len_sq = (pt.x * pt.x) + \
(pt.y * pt.y) + \
(pt.z * pt.z);
		if (len_sq < 1)
			return (pt);
	}
}

/*
 * generate & returns a random unit vector that lies within the unit sphere
 * (unit_sphere: x sq + y sq + z sq = 1)
 * len_sq <= 1 is to make sure the vector is within sphere (with unit len of 1)
 */
t_vector3d	rand_unit_vec(unsigned int *seed)//, t_vector3d surf_norm)
{
	t_vector3d	pt;
	float		len_sq;

	while (1)
	{
		pt = rand_vec_range(seed, -1, 1);
		// /*debug*/printf("gen: %f %f %f\n", res.x, res.y, res.z);
		len_sq = (pt.x * pt.x) + \
(pt.y * pt.y) + \
(pt.z * pt.z);
		if (len_sq > 0.00001f && len_sq <= 1)
			return (div_vec_scalar(pt, sqrt(len_sq)));
	}
}

/* returns a random vector that lies on sphere surface */
// t_vector3d	rand_on_hemisphere(unsigned int *seed, t_vector3d surf_norm)
// {
// 	t_vector3d	vec;

// 	vec = new_vector3d(-2, -2, -2);
// 	while (vec.x == -2)
// 		vec = norm_rand_vec(seed);
// 	// /*debug*/printf("rand_on_h:%f %f %f\n", vec.x, vec.y, vec.z);
// 	if (scalar_product(vec, surf_norm) <= 0)
// 		return (multiply_vec_scalar(vec, -1));
// 	// /*debug*/printf("rand_on_h:dot: %f\n", scalar_product(vec, surf_norm));
// 	return (vec);
// }

t_vector3d	rand_vec_range(unsigned int *seed, float min, float max)
{
	t_vector3d	res;

	res = new_vector3d(rand_lcg_range(seed, min, max), \
rand_lcg_range(seed, min, max), \
rand_lcg_range(seed, min, max));
	return (res);
}


