/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_lstadd_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// static void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("[%s]", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("\n");
// }
//
// int	main(void)
// {
// 	t_list	*lst;
//
// 	lst = NULL;
// 	ft_lstadd_back(&lst, ft_lstnew("A"));
// 	ft_lstadd_back(&lst, ft_lstnew("B"));
// 	ft_lstadd_back(&lst, ft_lstnew("C"));
// 	print_list(lst);
// }
