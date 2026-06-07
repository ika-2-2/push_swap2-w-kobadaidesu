/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_lstsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	*lst;
//
// 	lst = ft_lstnew("A");
// 	ft_lstadd_back(&lst, ft_lstnew("B"));
// 	ft_lstadd_back(&lst, ft_lstnew("C"));
// 	printf("size: %d\n", ft_lstsize(lst));
// 	printf("NULL: %d\n", ft_lstsize(NULL));
// }
