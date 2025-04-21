/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:05:22 by hsim              #+#    #+#             */
/*   Updated: 2025/04/21 15:28:17 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * initialize mlx windows for image rendering
 * mlx_init uses malloc
 */
void	initialize_mlx(t_vars *vars)
{
	vars->mlxconnect = mlx_init();
	if (vars->mlxconnect == NULL)
	{
		free(vars->mlxconnect);
		exit (1);
	}
	vars->mlxwindow = mlx_new_window(vars->mlxconnect, WIN_WIDTH, WIN_HEIGHT, \
"miniRT");
}
