/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_lstadd_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
// 	ft_lstadd_front(&lst, ft_lstnew("C"));
// 	ft_lstadd_front(&lst, ft_lstnew("B"));
// 	ft_lstadd_front(&lst, ft_lstnew("A"));
// 	print_list(lst);
// }
