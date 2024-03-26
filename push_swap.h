/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrito <sbrito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:51:56 by sbrito            #+#    #+#             */
/*   Updated: 2024/03/15 17:22:25 by sbrito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		main(int argc, char **argv);
void	sub_swap(int *stack, char direct);
void	sub_push(int *receiver, int *giver, char direct);
void	sub_rotate(int *stack, char direct);
void	sub_rerotate(int *stack, char direct);
void	sub_radix(int *stack_a, int *stack_b, int argc);
void	handle_special_cases(int *stack_a, int *stack_b, int bits);
int		sub_makeeasier(int *stack_a, int *stack_b, int argc);
int		sub_atol(const char *str, int *error);
long	ft_negative(char *c, int *i);
void	sub_okdoit(int *stack_b, int *stack_a, int bits);
int		sub_checkme(int *stack_a, int size, int plus);
void	sub_three(int *stack_b, int plus);
void	sub_five(int *stack_b, int *stack_a);
int		sub_okdoother(int *stack_a);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *bmemory, size_t len);

#endif