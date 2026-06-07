/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/05/08 14:28:45 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	dst[10];
// 	size_t	ret;
//
// 	ret = ft_strlcpy(dst, "hello", sizeof(dst));
// 	printf("dst: %s  ret: %zu\n", dst, ret);
// 	ret = ft_strlcpy(dst, "hello", 3);
// 	printf("size<len: dst=%s ret=%zu\n", dst, ret);
// 	ret = ft_strlcpy(dst, "hello", 0);
// 	printf("size=0: ret=%zu\n", ret);
// }
