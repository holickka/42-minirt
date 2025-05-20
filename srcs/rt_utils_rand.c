/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_rand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:15:24 by hsim              #+#    #+#             */
/*   Updated: 2025/05/20 08:22:31 by hsim             ###   ########.fr       */
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

