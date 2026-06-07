/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_strncmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_strncmp("abc", "abc", 3));   // 0
// 	printf("%d\n", ft_strncmp("abc", "abd", 3));   // 負
// 	printf("%d\n", ft_strncmp("abd", "abc", 3));   // 正
// 	printf("%d\n", ft_strncmp("abc", "abcd", 3));  // 0 (3文字一致)
// 	printf("%d\n", ft_strncmp("abc", "abcd", 4));  // 負 ('\0' vs 'd')
// 	printf("%d\n", ft_strncmp("abc", "abc", 0));   // 0 (n=0)
// }
