/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/16 15:47:18 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static char	*skip_sign_and_zeroes(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	return (str);
}

static int	is_int_range(char *str)
{
	int		negative;
	char	*limit;

	negative = (*str == '-');
	str = skip_sign_and_zeroes(str);
	if (negative)
		limit = "2147483648";
	else
		limit = "2147483647";
	if (ft_strlen(str) < ft_strlen(limit))
		return (1);
	if (ft_strlen(str) > ft_strlen(limit))
		return (0);
	return (ft_strcmp(str, limit) <= 0);
}

static int	has_duplicate(char **current, long n)
{
	char	**compare;

	compare = current + 1;
	while (*compare)
	{
		if (is_valid_number(*compare) && is_int_range(*compare)
			&& n == ft_atol(*compare))
			return (1);
		compare++;
	}
	return (0);
}

int	has_arg_error(char **args)
{
	char	**current;
	long	n;

	if (!args || !args[0])
		return (1);
	current = args;
	while (*current)
	{
		if (!is_valid_number(*current))
			return (1);
		if (!is_int_range(*current))
			return (1);
		n = ft_atol(*current);
		if (has_duplicate(current, n))
			return (1);
		current++;
	}
	return (0);
}
