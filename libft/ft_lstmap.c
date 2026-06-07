/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/06 06:26:30 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*content;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

// static void	*to_upper_str(void *content)
// {
// 	char	*s;
// 	char	*res;
// 	int		i;
//
// 	s = (char *)content;
// 	res = ft_strdup(s);
// 	i = 0;
// 	while (res[i])
// 	{
// 		if (res[i] >= 'a' && res[i] <= 'z')
// 			res[i] -= 32;
// 		i++;
// 	}
// 	return (res);
// }
//
// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*mapped;
// 	t_list	*tmp;
//
// 	lst = ft_lstnew(ft_strdup("hello"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("world")));
// 	mapped = ft_lstmap(lst, to_upper_str, free);
// 	tmp = mapped;
// 	while (tmp)
// 	{
// 		printf("[%s]\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&lst, free);
// 	ft_lstclear(&mapped, free);
// }
