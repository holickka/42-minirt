/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:02:00 by hsim              #+#    #+#             */
/*   Updated: 2025/05/05 18:13:58 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* prints error message, no \n needed*/
int	ft_perror(char *error_str, int return_value)
{
	if (error_str && error_str[0])
		ft_putstr_fd(error_str, 2);
	ft_putchar_fd('\n', 2);
	return (return_value);
}
