/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:59:22 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 14:45:33 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **stack, int flg)
{
	int		size;
	int		i;
	t_stack	*first;
	t_stack	*last;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	first = *stack;
	i = 1;
	while (i < size - 1)
	{
		*stack = (*stack)->next;
		i++;
	}
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	(*stack)->next = first;
	if (!flg)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack, int flg)
{
	int		size;
	int		i;
	t_stack	*first;
	t_stack	*last;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	first = *stack;
	i = 1;
	while (i < size - 1)
	{
		*stack = (*stack)->next;
		i++;
	}
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	(*stack)->next = first;
	if (!flg)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(&*stack_a, 1);
	rrb(&*stack_b, 1);
	ft_printf("rr\n");
}
