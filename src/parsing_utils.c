/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:38:28 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/23 17:25:17 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_robust_atoi_validations(const char *str, int *error_flag, int *i,
		int *sign)
{
	if (!str)
	{
		*error_flag = 1;
		return (0);
	}
	while (ft_isspace(str[(*i)]))
		(*i)++;
	if (str[(*i)] == '+' || str[(*i)] == '-')
	{
		if (str[(*i)] == '-')
		{
			*sign = -1;
		}
		(*i)++;
	}
	if (ft_isdigit(str[(*i)]) == 0)
	{
		*error_flag = 1;
		return (0);
	}
	return (1);
}

static int	ft_verify_int_overflow(int digit, int sign, long long result,
		int *error_flag)
{
	if (sign == 1)
	{
		if (result > MAX_INT / 10 || (result == MAX_INT / 10 && digit > MAX_INT
				% 10))
		{
			*error_flag = 1;
			return (0);
		}
	}
	else
	{
		if (result > ((long long)MAX_INT + 1) / 10
			|| (result == (((long long)MAX_INT + 1) / 10)
				&& digit > ((long long)MAX_INT + 1) % 10))
		{
			*error_flag = 1;
			return (0);
		}
	}
	return (1);
}

int	ft_robust_atoi(const char *str, int *error_flag)
{
	long long result;
	int i;
	int sign;
	int digit;

	i = 0;
	digit = 0;
	result = 0;
	sign = 1;
	if (!ft_robust_atoi_validations(str, error_flag, &i, &sign))
		return (0);
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (!ft_verify_int_overflow(digit, sign, result, error_flag))
			return (0);
		result = (result * 10) + digit;
		i++;
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
	{
		*error_flag = 1;
		return (0);
	}
	return ((int)(result * sign));
}