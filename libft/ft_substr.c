/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_substr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		new_str = malloc(1);
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	if (len > s_len - start)
		len = s_len - start;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}

// int	main(void)
// {
// 	printf("[%s]\n", ft_substr("hello world", 6, 5));  // [world]
// 	printf("[%s]\n", ft_substr("hello", 0, 3));        // [hel]
// 	printf("[%s]\n", ft_substr("hello", 10, 3));       // [] start>len
// 	printf("[%s]\n", ft_substr("hello", 0, 0));        // [] len=0
// 	printf("[%s]\n", ft_substr("hello", 2, 100));      // [llo] len>残り
// }
