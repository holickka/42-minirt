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
# include <stdbool.h> /* for bool */

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
#  define EPS 0.0001
# endif

# ifndef ROUND_UP
#  define ROUND_UP 0.5
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1280
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 800
# endif

typedef struct s_imgdata
{
	void		*image;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_imgdata;

typedef struct s_vars
{
	void		*mlxconnect;
	void		*mlxwindow;
	t_imgdata	img;
}	t_vars;

void	initialize_mlx(t_vars *vars);

/* __________________ key configurations __________________ */
int		close_window(int keycode, t_vars *vars);
int		close_window_x(int keycode, t_vars *vars);

/* __________________ memory free functions __________________ */
void	free_malloc(t_vars *vars, int indicator);



#endif