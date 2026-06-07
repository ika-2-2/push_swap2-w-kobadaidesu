/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_itoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+         */
/*   Created: 2026/05/06 00:00:00 by dakobaya        #+#    #+#               */
/*   Updated: 2026/05/06 00:00:00 by dakobaya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		cnt++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = count_digits(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[len - 1] = (num % 10 + '0');
		num /= 10;
		len--;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(42));
// 	printf("%s\n", ft_itoa(-42));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(2147483647));
// }
