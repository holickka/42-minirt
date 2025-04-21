/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:52:56 by hsim              #+#    #+#             */
/*   Updated: 2023/12/21 20:37:33 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

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

t_list	*ft_lstnew(char content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (newlist)
	{
		newlist->content = content;
		newlist->next = NULL;
		return (newlist);
	}
	return (NULL);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = ((*lst)->next);
		free(temp);
	}
}

int	ft_bzero(void *s, size_t n)
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

void	*ft_memcpy(void *dest, const void *src, char chr, size_t n)
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
