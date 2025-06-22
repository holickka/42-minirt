#ifndef MINIRT_H
# define MINIRT_H

# include "libftprintf.h"
# include "libft.h"
# include "get_next_line.h"
# include "keycode_macos.h"
# include "mousecode_macos.h"
# include "ft_vector.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h> /* for open() fd macros*/
# include <stdbool.h> /* for type bool */

/* remove during eval */
# include <stdio.h> /* for debug */


# ifndef ZOOM_FACTOR
#  define ZOOM_FACTOR 50
# endif

# ifndef PERSP_FACTOR
#  define PERSP_FACTOR 1
# endif

# ifndef ZOOM_IN_FACTOR
#  define ZOOM_IN_FACTOR 1.4
# endif

# ifndef ZOOM_OUT_FACTOR
#  define ZOOM_OUT_FACTOR 0.6
# endif

# ifndef ZOOM_MIN
#  define ZOOM_MIN 0.5
# endif

# ifndef ZOOM_MAX
#  define ZOOM_MAX 600
# endif

# ifndef EPS
#  define EPS 0.00001
# endif

# ifndef ROUND_UP
#  define ROUND_UP 0.5
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 600
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 400
# endif

enum	e_z_values
{
	NOW = 0,
	NEXT = 1,
};

enum	e_vector_values
{
	X = 0,
	Y = 1,
	Z = 2,
	W = 0,
	H = 1
};

enum	e_quadratic_values
{
	A = 0,
	C = 1
};

enum	e_material_type
{
	DIFFUSE,
	METAL,
	// DIELEC
	// BUBBLE
};

// enum	e_hsv_values
// {
// 	H = 0,
// 	S = 1,
// 	V = 2,
// 	// LOW = 0,
// 	// HIGH = 1,
// 	// NEG = 2,
// };

enum	e_rgb_values
{
	R = 0,
	G = 1,
	B = 2,
	RGB = 0,
	GBR = 1,
	BRG = 2
};

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef struct s_imgdata
{
	void		*image;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_imgdata;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	vector;
}	t_ray;

typedef struct s_mat
{
	t_uchar	type; //material type
	t_vec3	albedo; //obj base color
}	t_mat;

typedef struct s_sph
{
	t_vec3	orig; //origin
	float	rad; //radius
	t_mat	mat;

}	t_sph;

// typedef struct s_rgb
// {
// 	int	r;
// 	int	g;
// 	int	b;
// }	t_rgb;

// typedef struct s_obj
// {
// 	t_vector3d	*plane;
// 	t_vector3d	sphere; //make pointer later
// 	t_vector3d	*cyl;
// }	t_obj;

// typedef struct s_cam
// {

// }	t_cam;

typedef struct s_vars
{
	void		*mlxconnect;
	void		*mlxwindow;
	t_imgdata	img;

	//camera setup
	t_vec3			cam_orig;
	t_vec3			cam_lookat;
	t_vec3			vup; //vertical fov
	float			vfov; //vertical fov
	// float			focal_len;
	float			focus_dist;
	float			defoc_ang; //defocus angle
	t_vec3			defoc_disk[2];
	int				sample_per_pixel;
	unsigned char	ray_bounce; /* how many times a ray should bounce */
	t_vec3			color_bg[2];

	//obj
	int				count_sph;
	t_sph			*sph;
	t_ray			ray;
}	t_vars;

void		initialize_mlx(t_vars *vars);
void		init_variable(t_vars *vars);

/* __________________ img render __________________ */
void		my_mlx_pixel_put(t_vars vars, int x, int y, int color);
void		my_create_image(t_vars *vars, t_imgdata *img);
void		my_render_image(t_vars *vars);
void		clear_image(t_vars vars, int win_width, int win_height, int color);

/* __________________ ray __________________ */
float		has_hit_sphere(t_vec3 sphere, float radius, t_ray ray);
t_vec3		ray_color(t_vars vars, t_ray ray, unsigned char ray_bounce, unsigned int *seed);
// t_vector3d	ray_color_loop(t_vars vars, t_ray ray, unsigned int *seed);
t_ray		new_ray(t_vec3 origin, t_vec3 dir);

// int			ray_color(t_vars vars, t_ray ray);
int			sample_pixels(t_vars vars, t_vec3 target, t_vec3 viewport_d[2], int x);
t_vec3		sample_sq_rand(unsigned int *seed);

/* __________________ key configurations __________________ */
int			close_window(int keycode, t_vars *vars);
int			close_window_x(int keycode, t_vars *vars);

/* __________________ color lerp __________________ */
int			lerp_hsv(int *hsv1, int *hsv2, float t);
t_vec3		lerp_rgb(t_vec3 c1, t_vec3 c2, float t);
int			create_rgb(int r_value, int g_value, int b_value);
int			*create_hsv(int h_value, int s_value, int v_value);
// void	swap_value(int *num1, int *num2);
int			hsv_to_rgb(int *new_hsv);
t_vec3		split_rgb(int color);
// void		split_rgb(int color, int ptr[3]);

/* __________________ utils __________________ */
bool		is_near_zero(t_vec3 vec);

/* __________________ random __________________ */
float		rand_lcg(unsigned int *seed);
float		rand_lcg_range(unsigned int *seed, float min, float max);
t_vec3		rand_vec(unsigned int *seed);
t_vec3		rand_vec_range(unsigned int *seed, float min, float max);
t_vec3		rand_unit_vec(unsigned int *seed);
t_vec3		rand_unit_disk(unsigned int *seed);
// t_vector3d	rand_on_hemisphere(unsigned int *seed, t_vector3d surf_norm);

/* __________________ malloc functions __________________ */
int			malloc_sph_ptr(t_sph **dest, int num);

/* __________________ memory free functions __________________ */
void		free_malloc(t_vars *vars, int indicator);

/* __________________ debug functions __________________ */
void		debug_print_vec(char *str, t_vec3 vec);

#endif