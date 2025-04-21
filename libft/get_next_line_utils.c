/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:52:56 by hsim              #+#    #+#             */
/*   Updated: 2024/04/02 14:23:41 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back_gnl(t_list_gnl **lst, t_list_gnl *new)
{
	t_list_gnl	*temp;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}

t_list_gnl	*ft_lstnew_gnl(char content)
{
	t_list_gnl	*newlist;

	newlist = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (newlist)
	{
		newlist->content = content;
		newlist->next = NULL;
		return (newlist);
	}
	return (NULL);
}

void	ft_lstclear_gnl(t_list_gnl **lst)
{
	t_list_gnl	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = ((*lst)->next);
		free(temp);
	}
}

int	ft_bzero_gnl(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	if (!s)
		return (0);
	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
		temp[i++] = 0;
	return (1);
}

void	*ft_memcpy_gnl(void *dest, const void *src, char chr, size_t n)
{
	unsigned long	i;
	unsigned char	*tempdest;
	unsigned char	*tempsrc;

	tempdest = (unsigned char *)dest;
	tempsrc = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (tempdest);
	if (!dest && !src && !chr)
		return (NULL);
	while (i < n)
	{
		if (src && !chr)
			tempdest[i] = tempsrc[i];
		else if (chr && !src)
			tempdest[i] = (unsigned char)chr;
		i++;
	}
	return (tempdest);
}
