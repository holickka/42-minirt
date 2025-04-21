/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:13:07 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 19:13:46 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
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
/*
#include <stdio.h>

void	ft_printlist(t_list *content)
{
	printf("%s\n", (char *)content);
}
int	main()
{
	char c[] = "Linkedlist";
	ft_printlist(ft_lstnew(c));
}
*/
