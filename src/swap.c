/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:57:23 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 14:47:37 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **stack, int flg)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (!flg)
		ft_printf("sa\n");
}

void	sb(t_stack **stack, int flg)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (!flg)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(&*stack_a, 1);
	sb(&*stack_b, 1);
	write(1, "ss\n", 3);
}
