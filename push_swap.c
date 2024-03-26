/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:51:48 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/18 17:36:33 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief receives data on stack A and uses stack B to sort them
/// use bash when Args are compiled in one statement 
/// @param args numbers to be sorted, have to be converted to int
/// @return return 0 on error
int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	int	error;

	i = -1;
	error = 0;
	stack_a = ft_calloc(argc, sizeof(int));
	stack_b = ft_calloc(argc, sizeof(int));
	while (++i < argc - 1)
		stack_a[argc - 2 - i] = sub_atol(argv[i + 1], &error);
	if (error == 1)
	{
		write(2, "Error\n", 6);
		return (free(stack_a), free(stack_b), 1);
	}
	if (sub_makeeasier(stack_a, stack_b, argc - 1))
	{
		write(2, "Error\n", 6);
		return (free(stack_a), free(stack_b), 1);
	}
	free(stack_a);
	stack_a = ft_calloc(argc, sizeof(int));
	sub_radix(stack_a, stack_b, argc - 1);
	return (free(stack_a), free(stack_b), 0);
}

int	sub_makeeasier(int *stack_a, int *stack_b, int argc)
{
	int	i;
	int	j;
	int	temp;
	int	pos;

	i = 0;
	while (i != argc)
	{
		j = 0;
		temp = INT_MIN;
		while (j != argc)
		{
			if (temp == stack_a[j] && stack_b[j])
				return (1);
			if (temp <= stack_a[j] && !stack_b[j])
			{
				temp = stack_a[j];
				pos = j;
			}
			j++;
		}
		stack_b[pos] = argc - i;
		i++;
	}
	return (0);
}

void	sub_okdoit(int *stack_b, int *stack_a, int bits)
{
	int	stack_size;
	int	i;
	int	j;

	i = 0;
	while (bits > i)
	{
		stack_size = sub_okdoother(stack_a);
		j = stack_size + 1;
		if (sub_checkme(stack_a, stack_size, 0))
			return ;
		while (j--)
		{
			if (!(stack_a[stack_size] & (1 << i)))
			{
				sub_push(stack_b, stack_a, 'a');
				stack_size--;
			}
			else
				sub_rotate(stack_a, 'a');
		}
		while (stack_b[0] != '\0')
			sub_push(stack_a, stack_b, 'b');
		i++;
	}
}

/// @brief checks if the stack is done prematurely
/// @param stack_a the stack to be checked
/// @param plus offset used for edgecase
int	sub_checkme(int *stack_a, int size, int plus)
{
	int	i;

	i = 0;
	while (i != size)
	{
		if (stack_a[size - i] != i + 1 + plus)
			return (0);
		i++;
	}
	return (1);
}
