/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_lstnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	t_list	*node;
//
// 	node = ft_lstnew("hello");
// 	printf("content: %s\n", (char *)node->content);
// 	printf("next:    %p\n", (void *)node->next);
// 	node = ft_lstnew(NULL);
// 	printf("NULL content: %p\n", node->content);
// }
