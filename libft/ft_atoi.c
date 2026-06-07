/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_atoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("42"));          // 42
// 	printf("%d\n", ft_atoi("  -42"));       // -42
// 	printf("%d\n", ft_atoi("+100abc"));     // 100
// 	printf("%d\n", ft_atoi("0"));           // 0
// 	printf("%d\n", ft_atoi(""));            // 0
// 	printf("%d\n", ft_atoi("   "));         // 0
// 	printf("%d\n", ft_atoi("+"));           // 0
// 	printf("%d\n", ft_atoi("abc"));         // 0
// }
