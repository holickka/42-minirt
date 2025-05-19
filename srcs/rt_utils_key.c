/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:07:08 by hsim              #+#    #+#             */
/*   Updated: 2025/04/25 20:19:15 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*dont use mlx_destroy_window, have fsan error*/
int	close_window(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		free_malloc(vars, 1);
		exit (0);
	}
	return (0);
}

/* only for linux system, can remove this for mac system */
int	close_window_x(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	exit (0);
	return (0);
}
