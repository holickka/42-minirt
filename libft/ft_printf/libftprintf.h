/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:58:23 by hsim              #+#    #+#             */
/*   Updated: 2024/03/14 20:58:54 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putnbr_ux(unsigned long long n, char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putptr(void *n);
int		ft_putptr_hex(unsigned long long n, char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_checkinvalid(char *str);
int		ft_printf(const char *str, ...);
void	ft_bzero(void *s, size_t n);

#endif
