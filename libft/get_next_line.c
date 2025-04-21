/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:24:53 by hsim              #+#    #+#             */
/*   Updated: 2024/04/02 14:24:14 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_combinestring(t_list_gnl *lst)
{
	t_list_gnl	*temp;
	char		*tab;
	char		*oritab;
	int			lstsize;

	if (!lst)
		return (NULL);
	temp = lst;
	lstsize = 0;
	while (temp)
	{
		lstsize++;
		temp = temp->next;
	}
	tab = (char *)malloc((lstsize + 1) * sizeof(char));
	ft_bzero_gnl(tab, lstsize + 1);
	oritab = tab;
	temp = lst;
	while (temp)
	{
		ft_memcpy_gnl(tab++, 0, temp->content, 1);
		temp = temp->next;
	}
	return (oritab);
}

static int	scanbuffer(char *buffer, t_list_gnl **tab, char **leftover)
{
	int	i;
	int	wordcount;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		ft_lstadd_back_gnl(tab, ft_lstnew_gnl(buffer[i++]));
	if (buffer[i] == '\n')
	{
		ft_lstadd_back_gnl(tab, ft_lstnew_gnl(buffer[i++]));
		if (buffer[i])
		{
			wordcount = ft_strlen(&buffer[i]);
			*leftover = (char *)malloc((wordcount + 1) * sizeof(char));
			ft_bzero_gnl(*leftover, wordcount + 1);
			ft_memcpy_gnl(*leftover, &buffer[i], 0, wordcount);
		}
		return (0);
	}
	if (!buffer[i])
		ft_bzero_gnl(buffer, BUFFER_SIZE + 1);
	return (1);
}

static void	loadleftover(char *buffer, char **leftover)
{
	ft_memcpy_gnl(buffer, *leftover, 0, ft_strlen(*leftover));
	free(*leftover);
	*leftover = NULL;
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	char		*result;
	t_list_gnl	*tab;

	tab = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, &buffer, 0) < 0))
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!ft_bzero_gnl(buffer, BUFFER_SIZE + 1))
		return (NULL);
	if (leftover)
		loadleftover(buffer, &leftover);
	if (!leftover && scanbuffer(buffer, &tab, &leftover))
	{
		while (read(fd, buffer, BUFFER_SIZE) > 0)
		{
			if (!scanbuffer(buffer, &tab, &leftover))
				break ;
		}
	}
	result = ft_combinestring(tab);
	ft_lstclear_gnl(&tab);
	free(buffer);
	return (result);
}
