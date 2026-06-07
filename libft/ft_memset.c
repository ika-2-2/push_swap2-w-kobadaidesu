/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_memset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	buf[6] = "hello";
//
// 	ft_memset(buf, 'x', 3);
// 	printf("%s\n", buf);
// 	ft_memset(buf, 0, 5);
// 	printf("zeroed: %d\n", buf[0]);
// }
