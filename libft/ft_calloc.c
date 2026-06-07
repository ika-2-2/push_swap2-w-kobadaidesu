/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_calloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// int	main(void)
// {
// 	int	*arr;
// 	int	i;
//
// 	arr = (int *)ft_calloc(5, sizeof(int));
// 	i = 0;
// 	while (i < 5)
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// 	free(arr);
// 	printf("nmemb=0:  %p\n", ft_calloc(0, 4));
// 	printf("overflow: %p\n", ft_calloc((size_t)-1, 2));
// }
