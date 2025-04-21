/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:12:48 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 21:25:23 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = *lst;
		(del)((*lst)->content);
		*lst = ((*lst)->next);
		free(temp);
	}
}
/*
#include <stdio.h>
#include <string.h>
int	ft_lstsize(t_list *lst);
void	ft_del(void *myList)
{
	free(myList);
}
int	main()
{
	t_list	*mylst1;
	t_list	*mylst2;
	t_list	*mylst3;

	mylst1 = (t_list *)malloc(sizeof(t_list));
	mylst2 = (t_list *)malloc(sizeof(t_list));
	mylst3 = (t_list *)malloc(sizeof(t_list));

	mylst1->content = strdup("Hello");
	mylst1->next = mylst2;
	mylst2->content = strdup("What");
	mylst2->next = mylst3;
	mylst3->content = strdup("Yeay");
	mylst3->next = NULL;

	ft_lstclear(&mylst1, &ft_del);
	printf("%d\n", ft_lstsize(mylst1));
}
*/
