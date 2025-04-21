/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:07:37 by hsim              #+#    #+#             */
/*   Updated: 2025/04/21 15:22:50 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main()
{
	t_vars	vars;

	initialize_mlx(&vars);

	/* _____________close windows_____________ */
	mlx_hook(vars.mlxwindow, 17, 0, close_window_x, &vars);
	mlx_key_hook(vars.mlxwindow, close_window, &vars);
	
	mlx_loop(vars.mlxconnect);
	return (0);
}