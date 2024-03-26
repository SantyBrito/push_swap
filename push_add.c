/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:51:18 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/02 15:51:34 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sub_okdoother(int *stack_a)
{
	int	stack_size;

	stack_size = 0;
	while (stack_a[stack_size])
		stack_size++;
	stack_size--;
	return (stack_size);
}

void	sub_three(int *stack, int plus)
{
	int	compr;

	compr = stack[2];
	if (sub_checkme(stack, 2, plus) == 1)
		return ;
	if (compr < stack[1] && compr > stack[0])
		sub_rerotate(stack, 'a');
	if (compr < stack[1] && compr < stack[0])
		sub_rerotate(stack, 'a');
	if (compr > stack[1] && compr < stack[0])
		sub_swap(stack, 'a');
	if (compr > stack[1] && compr > stack[0])
		sub_rotate(stack, 'a');
	sub_three(stack, plus);
}

void	sub_five(int *stack_b, int *stack_a)
{
	int	i;

	i = 1;
	if (sub_checkme(stack_b, 4, 0))
		return ;
	while (i != 3)
	{
		if (stack_b[1] == i)
			sub_rerotate(stack_b, 'a');
		if (stack_b[0] == i)
			sub_rerotate(stack_b, 'a');
		else
			while (stack_b[4 - (i - 1)] != i)
				sub_rotate(stack_b, 'a');
		sub_push(stack_a, stack_b, 'a');
		i++;
	}
	sub_three(stack_b, 2);
	sub_push(stack_b, stack_a, 'b');
	sub_push(stack_b, stack_a, 'b');
}

/// @brief calls for memory and signs it with 0's
/// @param count how much memory
/// @param size the size of each block of memory
/// @return returns the allocated memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = malloc(size * count);
	if (!memory)
		return (0);
	ft_bzero(memory, size * count);
	return (memory);
}

/// @brief terminates a string with 0's
/// @param string the given string
/// @param ncount how many characters are turned into 0
void	ft_bzero(void *bmemory, size_t len)
{
	size_t			i;
	unsigned char	*mcpy;

	mcpy = (unsigned char *)bmemory;
	i = 0;
	while (i < len)
		mcpy[i++] = (unsigned char)0;
}
