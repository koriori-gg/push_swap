/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:08:09 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 14:46:47 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **stack, int flg)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (!flg)
		ft_printf("ra\n");
}

void	rb(t_stack **stack, int flg)
{
	int		size;
	t_stack	*tmp;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (!flg)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(&*stack_a, 1);
	rb(&*stack_b, 1);
	ft_printf("rr\n");
}
