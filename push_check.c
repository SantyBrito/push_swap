/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:52:54 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/18 20:59:02 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief removes abundance of - and +, turning a string into long
/// Specialized to handle errors for push_swap
/// @param str string input
/// @return returns an int
int	sub_atol(const char *str, int *error)
{
	long	result;
	long	minus;
	int		i;

	i = 0;
	minus = 1;
	result = 0;
	minus = ft_negative((char *)str, &i);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (*error = 1, 0);
		else
			result = result * 10 + (str[i] - '0');
		i++;
	}
	if (i > 11 || (i == 1 && (str[0] > '9' || str[0] < '0')))
		return (*error = 1, 0);
	if (result == 2147483647 && minus == -1)
		return (-2147483648);
	if (result > 2147483647 || result < -2147483648)
		return (*error = 1, 0);
	return ((int)result * (int)minus);
}

long	ft_negative(char *c, int *i)
{
	int	negative;

	negative = 1;
	while (c[*i] == '-' || c[*i] == '+')
	{
		if (c[*i] == '-')
			negative *= -1;
		(*i)++;
	}
	return (negative);
}

void	handle_special_cases(int *stack_a, int *stack_b, int bits)
{
	if (bits == 2)
	{
		if (stack_b[0] < stack_b[1])
			sub_swap(stack_b, 'a');
		return ;
	}
	else if (bits == 3)
	{
		sub_three(stack_b, 0);
		return ;
	}
	else if (bits == 5)
	{
		sub_five(stack_b, stack_a);
		return ;
	}
}

void	sub_radix(int *stack_a, int *stack_b, int bits)
{
	int	count;

	count = 0;
	handle_special_cases(stack_a, stack_b, bits);
	while (bits != 0)
	{
		bits >>= 1;
		count++;
	}
	bits = count;
	sub_okdoit(stack_a, stack_b, count);
}
