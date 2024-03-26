/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:51:40 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/15 12:52:23 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief swaps the first and second value of an array with eachother
/// @param stack the array given, name is misleading
void	sub_swap(int *stack, char direct)
{
	int	temp;
	int	count;

	count = 0;
	while (stack[count])
		count++;
	count--;
	temp = stack[count];
	stack[count] = stack[count - 1];
	stack[count - 1] = temp;
	if (direct == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

/// @brief pushes the value from giver to receiver
/// @param receiver the array to receive the value
/// @param giver the array that gives the value
void	sub_push(int *receiver, int *giver, char direct)
{
	int	counta;
	int	countb;

	counta = 0;
	while (giver[counta])
		counta++;
	counta--;
	countb = 0;
	while (receiver[countb])
		countb++;
	if (counta == -1)
		return ;
	receiver[countb] = giver[counta];
	giver[counta] = '\0';
	if (direct == 'a')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

/// @brief rotates the stack
/// @param stack array to get rotated
/// @param direct which stack is rotated (a or b)
void	sub_rotate(int *stack, char direct)
{
	int	temp;
	int	i;
	int	count;

	count = 0;
	while (stack[count])
		count++;
	count--;
	if (count == -1)
		return ;
	i = count;
	temp = stack[count];
	while (i != 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	if (direct == 'a')
		write(1, "ra\n", 3);
	else if (direct == 'b')
		write(1, "rb\n", 3);
}

/// @brief reverse rotates the stack
/// @param stack array to get rotated
/// @param direct which stack is rotated (a or b)
void	sub_rerotate(int *stack, char direct)
{
	int	temp;
	int	i;
	int	count;

	count = 0;
	while (stack[count])
		count++;
	count--;
	if (count == -1)
		return ;
	i = 1;
	temp = stack[0];
	while (i != count + 1)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	stack[count] = temp;
	if (direct == 'a')
		write(1, "rra\n", 4);
	else if (direct == 'b')
		write(1, "rrb\n", 4);
}
