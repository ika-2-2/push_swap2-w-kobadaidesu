/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_memcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	unsigned char	src[5] = {1, 2, 3, 4, 5};
// 	unsigned char	dst[5] = {0};
//
// 	ft_memcpy(dst, src, 5);
// 	printf("%d %d %d %d %d\n", dst[0], dst[1], dst[2], dst[3], dst[4]);
// 	ft_memcpy(dst, src, 0);
// 	printf("n=0: %d\n", dst[0]);
// }
