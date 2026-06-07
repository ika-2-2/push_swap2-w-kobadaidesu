/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_strlcat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len == size)
		return (size + src_len);
	while (src[i] != '\0' && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	dst[20];
// 	size_t	ret;
//
// 	// 通常: "Hello" + " World" → "Hello World", ret=11
// 	ft_strlcpy(dst, "Hello", sizeof(dst));
// 	ret = ft_strlcat(dst, " World", sizeof(dst));
// 	printf("normal:   dst=%s ret=%zu\n", dst, ret);
//
// 	// size=0: dst触らず、ret=src_len=6
// 	ft_strlcpy(dst, "Hello", sizeof(dst));
// 	ret = ft_strlcat(dst, " World", 0);
// 	printf("size=0:   dst=%s ret=%zu\n", dst, ret);
//
// 	// size=1: NUL終端のみ、追記なし、ret=0+6=6
// 	dst[0] = '\0';
// 	ret = ft_strlcat(dst, " World", 1);
// 	printf("size=1:   dst=%s ret=%zu\n", dst, ret);
//
// 	// size==dstlen: 追記不可、ret=size+srclen
// 	ft_strlcpy(dst, "Hello", sizeof(dst));
// 	ret = ft_strlcat(dst, " World", 5);
// 	printf("size=dstlen: dst=%s ret=%zu\n", dst, ret);
// }
