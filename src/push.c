/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:07:23 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 14:46:10 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*stack_b);
	if (size <= 0)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_stackadd_front(stack_a, tmp);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*stack_a);
	if (size <= 0)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_stackadd_front(stack_b, tmp);
	ft_printf("pb\n");
}
