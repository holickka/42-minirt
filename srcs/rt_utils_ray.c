/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:18:16 by hsim              #+#    #+#             */
/*   Updated: 2025/05/19 19:12:31 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	shoot_rays()
// {
// 	t_vector3d	cam;

// 	cam = new_vector3d(0, 0, 0);
// }

/* 
 * derived from quadratic equation discriminant formula
 * b sq - 4ac >= 0 (hit sphere)
 * b sq - 4ac < 0 (doesnt hit sphere)
 * full formula:
 * [-b +- sqrt(b sq - 4ac)]  /  2a
 * shortened:
 * [b +- sqrt(b sq - ac)]  /  a
 * 
 * res = discriminant
 * expanded frm sphere equation x sq + y sq + z sq - r sq = 0
 * vector from point P on ray -> sphere center C
 * 
 * returns the closest point if there are 2 roots
 * 
 * formula expansion reference:
 * https://raytracing.github.io/books/RayTracingInOneWeekend.html
 * https://youtu.be/ebzlMOw79Yw?si=8SXTPsEcSUtwft71
 */
float	has_hit_sphere(t_vector3d sph_orig, float radius, t_ray ray)
{
	float		n[3];
	float		res;
	float		tmp;
	float		uint_max = 4294967295;
	t_vector3d	ray_to_center;

	(void)	radius;

	/* check all objs/sph to see which is the closest hit */

	ray_to_center = subtract_vector(sph_orig, ray.origin);
	n[A] = scalar_product(ray.vector, ray.vector) + EPS;
	n[B] = scalar_product(ray.vector, ray_to_center) + EPS;
	n[C] = scalar_product(ray_to_center, ray_to_center) - (radius * radius) + EPS;

	res = (n[B] * n[B]) - (n[A] * n[C]);
	// return (res >= 0);
	if (res < 0)
		return (-1); // if there's no solution
	// /*debug*/printf("has_hit_sphere:a:%f\n", a);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", a, b, c);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", b, res, a);
	// /*debug*/printf("has_hit_sphere:%f\n", res);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", ray.vector.x, ray.vector.y, ray.vector.z);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", ray_to_center.x, ray_to_center.y, ray_to_center.z);
	tmp = (n[B] - sqrt(res)) / n[A];
	if (tmp <= 0 || tmp >= uint_max)
		tmp = (n[B] + sqrt(res)) / n[A];
	/*debug*/printf("has_hit_sphere:%f %f\n", res, INFINITY);

	if (tmp <= 0 || tmp >= uint_max)
		return (-1);

	return (tmp);

	// return ((b - sqrt(res)) / a);
}

/* 3d point along a vector ray */
t_vector3d	point_at(float t, t_ray r)
{
	return (add_vector(r.origin, multiply_vector_scalar(r.vector, t)));
}

/*
 * calculates vector pt_ray -> sphere_center
 * if scalar_product of ray . surf_norm > 0, (means ray hits inner side)
 * reverse direction of surf_norm
 * returns a surf_norm in unit vector
 */
t_vector3d	get_surf_norm(t_ray ray, t_vector3d sph_center, float t)
{
	t_vector3d	pt_ray;
	t_vector3d	surf_norm;

	// also known as set_face_normal
	pt_ray = add_vector(ray.origin, multiply_vector_scalar(ray.vector, t)); // .at
	surf_norm = subtract_vector(pt_ray, sph_center);
	surf_norm = norm_vector3d(surf_norm); // div by radius
	// if dot product of 2 vecs > 0
	// means they're pointing in same direction
	// == ray comes from inside
	// so, reverse surf_norm if so
	if (scalar_product(ray.vector, surf_norm) > 0)
		surf_norm = multiply_vector_scalar(surf_norm, -1);
	return (surf_norm);
}

/*
 * child function in ray_color
 * checks if ray hits any surface
 * returns the closest point ray hits
 */
bool	hit(t_vars vars, int ray_max, t_vector3d *pt_ray)
{
	int			x;
	float		t;
	bool		res;
	float		min;

	x = -1;
	res = 0;
	min = ray_max;
	while (++x < vars.count_sph)
	{
		/*debug*/printf("id:%d\n", x);
		t = has_hit_sphere(vars.sph[x].orig, vars.sph[x].rad, vars.ray);
		/*debug*/printf("has_hit_sphere:t:%f\n", t);
		if (t > 0 && t < min)
		{
			res = 1;
			min = t;
			*pt_ray = get_surf_norm(vars.ray, vars.sph[x].orig, t);
		}
	}
	return (res);
}

/*
 * child function in ft_draw
 * checks if ray hits any object
 * defines what color should the ray be
 */
int	ray_color(t_vars vars, t_ray ray)
{
	float		t;
	t_vector3d	pt_ray;

	(void)	vars;

	// ray_norm = norm_vector3d(ray.vector);
	// if (has_hit_sphere(new_vector3d(0, 0, -1), radius, ray))
		// return (0xFF8080);

	if (hit(vars, 2147483647, &pt_ray))
		return (create_rgb(0.5*255*(pt_ray.x+1), 0.5*255*(pt_ray.y+1), 0.5*255*(pt_ray.z+1)));

	/* else render sky bg */
	// ray_norm = ray.vector;
	t = (ray.vector.y + 1) / 2;
	// /*debug*/printf("ray_color:t:%f ray.y:%f %f\n", t, ray.vector.y, ray_norm.y);
	return (lerp_hsv(vars.color_bg[1], vars.color_bg[0], t));
}

// if (t > 0)
// {
// // 	/* get point_on_ray */
// // 	// pt_ray = add_vector(ray.origin, multiply_vector_scalar(ray.vector, t));
// // 	pt_ray = get_surf_norm(ray, vars.sph[0].orig, t);

// // 	/* pt_ray -> sph_center == surf_norm */
// // 	/* if is unit_vector, magnitude = radius */

// // 	/* convert to unit vector */
// // 	// t_vector3d tmp = new_vector3d(pt_ray.x/radius, pt_ray.y/radius, pt_ray.z/radius);
// // 	// t_vector3d tmp2 = norm_vector3d(pt_ray);
// // 	/*debug*/printf("ray_color:2:%f %f %f\n", tmp2.x, tmp2.y, tmp2.z);

// // 	/*render color normal*/

// // color based on surface normal
// 	return (create_rgb(0.5*255*(pt_ray.x+1), 0.5*255*(pt_ray.y+1), 0.5*255*(pt_ray.z+1)));
// }