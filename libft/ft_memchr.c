/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_memchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	unsigned char	buf[5] = {1, 2, 3, 4, 5};
// 	unsigned char	*res;
//
// 	res = ft_memchr(buf, 3, 5);
// 	printf("found:     %d\n", *res);
// 	res = ft_memchr(buf, 9, 5);
// 	printf("not found: %s\n", res ? "found" : "NULL");
// 	res = ft_memchr(buf, 1, 0);
// 	printf("n=0:       %s\n", res ? "found" : "NULL");
// }
