/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/05/06 03:28:00 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

// int	main(void)
// {
// 	unsigned char	buf1[8] = {1, 2, 3, 4, 5, 6, 7, 8};
// 	unsigned char	buf2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//
// 	ft_memmove(buf1 + 2, buf1, 5);
// 	printf("dest>src: %d %d %d %d %d\n",
// 		buf1[2], buf1[3], buf1[4], buf1[5], buf1[6]);
// 	ft_memmove(buf2, buf2 + 2, 5);
// 	printf("dest<src: %d %d %d %d %d\n",
// 		buf2[0], buf2[1], buf2[2], buf2[3], buf2[4]);
// }
