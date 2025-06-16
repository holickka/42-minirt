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
	Z = 2
};

enum	e_quadratic_values
{
	A = 0,
	C = 1
};

enum	e_material_type
{
	DIFFUSE,
	METAL
};

enum	e_hsv_values
{
	H = 0,
	S = 1,
	V = 2,
	// LOW = 0,
	// HIGH = 1,
	// NEG = 2,
};

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
	t_vector3d	origin;
	t_vector3d	vector;
}	t_ray;

typedef struct s_mat
{
	t_uchar		type; //material type
	t_vector3d	albedo; //obj base color
}	t_mat;

typedef struct s_sph
{
	t_vector3d	orig; //origin
	float		rad; //radius
	t_mat		mat;

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

typedef struct s_vars
{
	void			*mlxconnect;
	void			*mlxwindow;
	int				focal_len;
	// int				*color_bg[2];
	t_vector3d		color_bg[2];
	int				count_sph;
	int				sample_per_pixel;
	unsigned char	ray_bounce; /* how many times a ray should bounce */
	t_sph			*sph;
	t_ray			ray;
	t_vector3d		cam_center;
	t_imgdata		img;
}	t_vars;

void		initialize_mlx(t_vars *vars);
void		init_variable(t_vars *vars);

/* __________________ img render __________________ */
void		my_mlx_pixel_put(t_vars vars, int x, int y, int color);
void		my_create_image(t_vars *vars, t_imgdata *img);
void		my_render_image(t_vars vars);
void		clear_image(t_vars vars, int win_width, int win_height, int color);

/* __________________ ray __________________ */
float		has_hit_sphere(t_vector3d sphere, float radius, t_ray ray);
t_vector3d	ray_color(t_vars vars, t_ray ray, unsigned char ray_bounce, unsigned int *seed);
t_vector3d	ray_color_loop(t_vars vars, t_ray ray, unsigned int *seed);
t_ray		new_ray(t_vector3d origin, t_vector3d dir);

// int			ray_color(t_vars vars, t_ray ray);
int			sample_pixels(t_vars vars, t_vector3d target, t_vector3d viewport_d, int x);
t_vector3d	sample_sq_rand(unsigned int *seed);

/* __________________ key configurations __________________ */
int			close_window(int keycode, t_vars *vars);
int			close_window_x(int keycode, t_vars *vars);

/* __________________ color lerp __________________ */
int			lerp_hsv(int *hsv1, int *hsv2, float t);
t_vector3d	lerp_rgb(t_vector3d c1, t_vector3d c2, float t);
int			create_rgb(int r_value, int g_value, int b_value);
int			*create_hsv(int h_value, int s_value, int v_value);
// void	swap_value(int *num1, int *num2);
int			hsv_to_rgb(int *new_hsv);
t_vector3d	split_rgb(int color);
// void		split_rgb(int color, int ptr[3]);

/* __________________ utils __________________ */
bool	is_near_zero(t_vector3d vec);

/* __________________ random __________________ */
float		rand_lcg(unsigned int *seed);
float		rand_lcg_range(unsigned int *seed, float min, float max);
t_vector3d	rand_vec(unsigned int *seed);
t_vector3d	rand_vec_range(unsigned int *seed, float min, float max);
t_vector3d	norm_rand_vec(unsigned int *seed);
t_vector3d	rand_on_hemisphere(unsigned int *seed, t_vector3d surf_norm);

// t_vector3d	norm_rand_vec(unsigned int *seed, t_vector3d surf_norm);

/* __________________ malloc functions __________________ */
int			malloc_sph_ptr(t_sph **dest, int num);

/* __________________ memory free functions __________________ */
void		free_malloc(t_vars *vars, int indicator);



#endif