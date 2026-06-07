/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_strrchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("hello", 'l'));
// 	printf("%s\n", ft_strrchr("hello", 'h'));
// 	printf("%p\n", (void *)ft_strrchr("hello", 'z'));
// 	printf("%s\n", ft_strrchr("hello", '\0'));
// }
