/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:54:48 by hsim              #+#    #+#             */
/*   Updated: 2024/04/02 14:24:15 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <stdlib.h> /* for malloc(), NULL */
# include <unistd.h> /* for close(), read() function */

typedef struct s_list_gnl
{
	char				content;
	struct s_list_gnl	*next;
}	t_list_gnl;

char		*get_next_line(int fd);
void		ft_lstadd_back_gnl(t_list_gnl **lst, t_list_gnl *new);
t_list_gnl	*ft_lstnew_gnl(char content);
void		ft_lstclear_gnl(t_list_gnl **lst);
int			ft_bzero_gnl(void *s, size_t n);
void		*ft_memcpy_gnl(void *dest, const void *src, char chr, size_t n);

#endif
