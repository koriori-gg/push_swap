/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:09:38 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 12:02:11 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//sort b
void	ft_sort_two_reverse(t_stack **stack)
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
	if (num[0] < num[1])
		rrb(stack, 0);
}

void	ft_sort_three_reverse(t_stack **stack)
{
	t_stack	*head;
	int		num[3];

	head = *stack;
	num[0] = head->value;
	num[1] = head->next->value;
	num[2] = head->next->next->value;
	if (num[0] < num[1] && num[1] < num[2] && num[0] < num[2])
	{
		rb(stack, 0);
		sb(stack, 0);
	}
	if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		rb(stack, 0);
	if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		rrb(stack, 0);
	if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		sb(stack, 0);
	if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
	{
		sb(stack, 0);
		rb(stack, 0);
	}
}

void	find_min(int count, int size, t_stack **a)
{
	if (count > size / 2)
	{
		while (size - count > 0)
		{
			rra(a, 0);
			count++;
		}
	}
	else
	{
		while (count > 0)
		{
			ra(a, 0);
			count--;
		}
	}
}

void	ft_move_min(int size, int border, t_stack **a, t_stack **b)
{
	t_stack	*head;
	int		count;

	head = *a;
	count = 0;
	while (count < size)
	{
		if (head->value <= border)
			break ;
		head = head->next;
		count++;
	}
	find_min(count, size, a);
	pb(a, b);
}

void	ft_sort_four_to_six(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	size = ft_stacksize(*a);
	i = 0;
	while (size - i > 3)
	{
		ft_move_min(size - i, size - 3, a, b);
		i++;
	}
	ft_sort_three(a);
	if (ft_stacksize(*b) == 3)
		ft_sort_three_reverse(b);
	else if (ft_stacksize(*b) == 2)
		ft_sort_two_reverse(b);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}
