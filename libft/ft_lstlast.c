/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:13:02 by hsim              #+#    #+#             */
/*   Updated: 2023/11/04 20:09:10 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
int	main()
{
	t_list	*mylst1;
	t_list	*mylst3;

	mylst1 = NULL;

	ft_lstadd_front(&mylst1, (t_list *)malloc(sizeof(t_list)));
	ft_lstadd_front(&mylst1, (t_list *)malloc(sizeof(t_list)));

	mylst3 = ft_lstnew("Hello");
	ft_lstlast(mylst1)->next = mylst3;

	printf("%s\n", (char *)(ft_lstlast(mylst1)->content));
	printf("%d\n", ft_lstsize(mylst1));
}
*/
