/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:54:48 by hsim              #+#    #+#             */
/*   Updated: 2023/12/31 20:46:03 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <limits.h> /* for OPEN_MAX */
# include <stdlib.h> /* for malloc(), NULL */
# include <unistd.h> /* for close(), read() function */

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char content);
void	ft_lstclear(t_list **lst);
int		ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, char chr, size_t n);

#endif
