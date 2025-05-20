/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:18:16 by hsim              #+#    #+#             */
/*   Updated: 2025/05/20 18:54:22 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
 * unsigned int max: 4294967295 as limit num
 * 
 * formula expansion reference:
 * https://raytracing.github.io/books/RayTracingInOneWeekend.html
 * https://youtu.be/ebzlMOw79Yw?si=8SXTPsEcSUtwft71
 */
float	has_hit_sphere(t_vector3d sph_orig, float radius, t_ray ray)
{
	float		n[3];
	float		discriminant;
	float		tmp;
	t_vector3d	ray_to_center;

	/* check all objs/sph to see which is the closest hit */

	ray_to_center = subtract_vector(sph_orig, ray.origin);
	n[A] = scalar_product(ray.vector, ray.vector) + EPS;
	n[B] = scalar_product(ray.vector, ray_to_center) + EPS;
	n[C] = scalar_product(ray_to_center, ray_to_center) - (radius * radius) + EPS;

	discriminant = (n[B] * n[B]) - (n[A] * n[C]);
	if (discriminant < 0)
		return (-1); // if there's no solution
	// /*debug*/printf("has_hit_sphere:a:%f\n", a);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", a, b, c);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", b, res, a);
	// /*debug*/printf("has_hit_sphere:%f\n", res);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", ray.vector.x, ray.vector.y, ray.vector.z);
	// /*debug*/printf("has_hit_sphere:%f %f %f\n", ray_to_center.x, ray_to_center.y, ray_to_center.z);
	tmp = (n[B] - sqrt(discriminant)) / n[A];
	if (tmp <= 0 || tmp >= 4294967295)
		tmp = (n[B] + sqrt(discriminant)) / n[A];
	/*debug*/printf("has_hit_sphere:%f %f\n", discriminant, INFINITY);

	if (tmp <= 0 || tmp >= 4294967295)
		return (-1);
	return (tmp);
}

t_vector3d	sample_sq_rand(unsigned int *seed)
{
	t_vector3d	pt;

	pt = new_vector3d(rand_lcg(seed) - 0.5, rand_lcg(seed) - 0.5, 0);
	// /*debug*/printf("sample_sq_rand:%f %f %f\n", pt.x, pt.y, pt.z);
	return (pt);
}

/*
 * generate random sampling point on pixels
 * and return the color sampled
 */
int	sample_pixels(t_vars vars, t_vector3d target, t_vector3d viewport_d, int x)
{
	int				k;
	unsigned int	seed;
	t_vector3d		offset;
	t_vector3d		color;
	t_vector3d		res;

	seed = 12345 + x;
	k = -1;
	color = new_vector3d(0, 0, 0);
	res.z = target.z;
	while (++k < vars.sample_per_pixel)
	{
		offset = sample_sq_rand(&seed);
		res.x = target.x + (offset.x * viewport_d.x);
		res.y = target.y + (offset.y * viewport_d.y);

		// get_ray
		// 0.5 + ((1 + 0.1) * 0.54)
		// 0.5 + (1 * 0.54) + (0.1 * 0.54)

		vars.ray.vector = subtract_vector(res, vars.cam_center);
		// vars.ray.vector = subtract_vector(target, vars.cam_center);
		/*debug*/printf("ft_draw:tar:%f %f %f\n", target.x, target.y, target.z);
		/*debug*/printf("ft_draw:res:%f %f %f\n", res.x, res.y, res.z);
		// /*debug*/printf("ft_draw:vp:%f %f %f\n", viewport_00.x, viewport_00.y, viewport_00.z);
		// /*debug*/printf("ft_draw:cam:%f %f %f\n", vars.ray.vector.x, vars.ray.vector.y,  vars.ray.vector.z);
		color = add_vector(color, ray_color(vars, vars.ray, vars.ray_bounce, &seed));
		/*debug*/printf("color:%f %f %f\n", color.x, color.y, color.z);
	}
	color = div_vector_scalar(color, vars.sample_per_pixel);
	return (create_rgb(color.x, color.y, color.z));
}

// t_ray	get_ray(int x, int y)
// {
// 	int			seed;
// 	t_vector3d	offset;
	
// 	seed = 12345 + x;
// 	offset = sample_sq_rand(&seed);

//     // ray get_ray(int i, int j) const {
//     //     // Construct a camera ray originating from the origin and directed at randomly sampled
//     //     // point around the pixel location i, j.

//     //     auto offset = sample_square();
//     //     auto pixel_sample = pixel00_loc
//     //                       + ((i + offset.x()) * pixel_delta_u)
//     //                       + ((j + offset.y()) * pixel_delta_v);

//     //     auto ray_origin = center;
//     //     auto ray_direction = pixel_sample - ray_origin;

//     //     return ray(ray_origin, ray_direction);
//     // }
// }

/*
 * 3d point along a vector ray
 * vec = origin + (t * direction)
 */
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
	if (scalar_product(ray.vector, surf_norm) > 0) // pointing in same direction
		surf_norm = multiply_vector_scalar(surf_norm, -1);
	return (surf_norm);
}

/*
 * child function in ray_color
 * checks if ray hits any surface
 * returns the closest point ray hits
 */
bool	hit(t_vars vars, t_ray ray, t_vector3d *surf_norm, t_vector3d *at)
{
	int			x;
	float		t;
	bool		res;
	float		min;

	x = -1;
	res = 0;
	min = 2147483647;
	// min = INFINITY;
	while (++x < vars.count_sph)
	{
		/*debug*/printf("id:%d\n", x);
		t = has_hit_sphere(vars.sph[x].orig, vars.sph[x].rad, ray);
		/*debug*/printf("has_hit_sphere:t:%f\n", t);
		if (t >= 0.001 && t <= min)
		{
			res = 1;
			min = t;
			*at = add_vector(ray.origin, multiply_vector_scalar(ray.vector, t));
			*surf_norm = get_surf_norm(ray, vars.sph[x].orig, t);
		}
	}
	return (res);
}

/*
 * child function in ft_draw
 * checks if ray hits any object
 * defines what color should the ray be
 */
t_vector3d	ray_color(t_vars vars, t_ray ray, unsigned char ray_bounce, unsigned int *seed)
{
	float		t;
	t_ray		bounce;
	t_vector3d	surf_norm;
	t_vector3d	color;

	if (ray_bounce <= 0)
		return (new_vector3d(0, 0, 0));

	// ray_norm = norm_vector3d(ray.vector);
	// if (has_hit_sphere(new_vector3d(0, 0, -1), radius, ray))
		// return (0xFF8080);

	if (hit(vars, ray, &surf_norm, &bounce.origin))
	{
		/* create new direction vector frm hit point */
		bounce.vector = rand_on_hemisphere(seed, surf_norm);
		return (div_vector_scalar(ray_color(vars, bounce, ray_bounce - 1, seed), 2));

// 		return (new_vector3d(0.5*255*(surf_norm.x+1), \
// 0.5*255*(surf_norm.y+1), \
// 0.5*255*(surf_norm.z+1)));
	}

	/* else render sky bg */
	t = (ray.vector.y + 1) / 2;
	// vec.y ranges from -1 to 1, add 1 makes it positive,
	// div 2 makes it 1

	// /*debug*/printf("ray_color:t:%f ray.y:%f %f\n", t, ray.vector.y, ray_norm.y);
	// t_vector3d c1;
	// t_vector3d c2;
	
	// c1.x = 229 * (1-t);
	// c1.y = 69 * (1-t);
	// c1.z = 69 * (1-t);

	// c2.x = 0*t;
	// c2.y = 175*t;
	// c2.z = 255*t;
	// color = add_vector(c1, c2);

	color = split_rgb(lerp_hsv(vars.color_bg[1], vars.color_bg[0], t));
	return (color);
}

// int	ray_color(t_vars vars, t_ray ray)
// {
// 	float		t;
// 	t_vector3d	pt_ray;
// 	// float		ratio = 1 / vars.sample_per_pixel;

// 	(void)	vars;

// 	// ray_norm = norm_vector3d(ray.vector);
// 	// if (has_hit_sphere(new_vector3d(0, 0, -1), radius, ray))
// 		// return (0xFF8080);

// 	if (hit(vars, 2147483647, &pt_ray))
// 		return (create_rgb(0.5*255*(pt_ray.x+1),
// 0.5*255*(pt_ray.y+1),
// 0.5*255*(pt_ray.z+1)));

// 	/* else render sky bg */
// 	// ray_norm = ray.vector;
// 	t = (ray.vector.y + 1) / 2;
// 	// /*debug*/printf("ray_color:t:%f ray.y:%f %f\n", t, ray.vector.y, ray_norm.y);
// 	return (lerp_hsv(vars.color_bg[1], vars.color_bg[0], t));
// }