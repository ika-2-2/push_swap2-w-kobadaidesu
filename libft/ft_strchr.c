/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_strchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strchr("hello", 'l'));
// 	printf("%p\n", (void *)ft_strchr("hello", 'z'));
// 	printf("%s\n", ft_strchr("hello", '\0'));
// }
