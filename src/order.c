/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:12:03 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/27 12:12:03 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	search_min(t_stack **stack)
{
	t_stack	*head;
	long	min;

	head = *stack;
	min = head->value;
	while (head != NULL)
	{
		if (min > head->value)
		{
			min = head->value;
		}
		head = head->next;
	}
	return (min);
}

int	search_max(t_stack **stack)
{
	t_stack	*head;
	long	max;

	head = *stack;
	max = head->value;
	while (head != NULL)
	{
		if (max < head->value)
		{
			max = head->value;
		}
		head = head->next;
	}
	return (max);
}
//flg : 1 降順 , 0 昇順
int	judge_order(t_stack **stack, int max, int min)
{
	t_stack	*pre;
	t_stack	*cur;
	t_stack	*nex;

	pre = ft_stacklast(*stack);
	cur = *stack;
	nex = cur ->next;
	while (nex != NULL)
	{
		if (cur->value != max && cur->value != min)
		{
			if (pre->value < cur->value && cur->value < nex->value)
				return (0);
			else if (pre->value > cur->value && cur->value > nex->value)
				return (1);
		}
		pre = cur;
		cur = cur->next;
		nex = nex->next;
	}
	nex = *stack;
	if (cur->value != max && cur->value != min)
	{
		if (pre->value < cur->value && cur->value < nex->value)
			return (0);
		else if (pre->value > cur->value && cur->value > nex->value)
			return (1);
	}
	return (0);
}
