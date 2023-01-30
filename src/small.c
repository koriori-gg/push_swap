/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:10:46 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 11:47:42 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_two(t_stack **stack)
{
	t_stack	*head;
	int		num[2];
	int		i;

	head = *stack;
	i = 0;
	while (head != NULL)
	{
		num[i] = head->value;
		head = head->next;
		i++;
	}
	if (num[0] > num[1])
		rra(stack, 0);
}

void	ft_sort_three(t_stack **stack)
{
	t_stack	*head;
	int		num[3];

	head = *stack;
	num[0] = head->value;
	num[1] = head->next->value;
	num[2] = head->next->next->value;
	if (num[0] > num[1] && num[1] < num[2] && num[0] <= num[2])
		sa(stack, 0);
	if (num[0] > num[1] && num[1] <= num[2] && num[0] > num[2])
		ra(stack, 0);
	if (num[0] <= num[1] && num[1] > num[2] && num[0] >= num[2])
		rra(stack, 0);
	if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
	{
		ra(stack, 0);
		sa(stack, 0);
	}
	if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
	{
		rra(stack, 0);
		sa(stack, 0);
	}
}
