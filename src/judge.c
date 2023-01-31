/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:02:56 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/31 12:02:56 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*pre;
	t_stack	*cur;

	pre = *stack;
	cur = pre->next;
	while (cur != NULL)
	{
		if (pre->value > cur->value)
			return (0);
		pre = pre->next;
		cur = cur->next;
	}
	return (1);
}
