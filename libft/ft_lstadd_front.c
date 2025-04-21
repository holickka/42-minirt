/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:14:45 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 19:14:45 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>
int	main()
{
	t_list	*initlist;
	t_list	*addlist;
	t_list	*addlist2;
	t_list	*temp;

	initlist = (t_list *)malloc(sizeof(t_list));
	initlist->content = "Originally First";
	initlist->next = NULL;

	addlist = (t_list *)malloc(sizeof(t_list));
	addlist->content = "Added to Front";
	addlist->next = NULL;

	addlist2 = (t_list *)malloc(sizeof(t_list));
	addlist2->content = "Me first";
	addlist2->next = NULL;

	ft_lstadd_front(&initlist, addlist);
	ft_lstadd_front(&initlist, addlist2);

	while(initlist)
	{
		printf("%s\n", (char *)initlist->content);
		initlist = initlist->next;
	}
	while(initlist)
	{
		temp = initlist;
		initlist = initlist->next;
		free(temp);
	}
	return (0);
}
*/
