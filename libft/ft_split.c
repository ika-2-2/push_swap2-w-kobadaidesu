/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/05/08 14:24:11 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*ft_free_result(char **result, int n)
{
	while (n > 0)
		free(result[--n]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		result[i] = ft_substr(s, 0, get_word_len(s, c));
		if (!result[i])
			return (ft_free_result(result, i));
		s += ft_strlen(result[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	**res;
// 	int		i;
//
// 	res = ft_split("hello world foo", ' ');
// 	i = 0;
// 	while (res[i])
// 		printf("[%s]\n", res[i++]);
// 	printf("---\n");
// 	res = ft_split(",,a,,b,,", ',');
// 	i = 0;
// 	while (res[i])
// 		printf("[%s]\n", res[i++]);
// 	printf("---\n");
// 	res = ft_split("", ' ');
// 	printf("empty: %s\n", res[0] ? res[0] : "NULL");
// 	res = ft_split("   ", ' ');
// 	printf("delimiters only: %s\n", res[0] ? res[0] : "NULL");
// }
