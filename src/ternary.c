/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:34:35 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/29 18:56:20 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ternary_digit(t_stack **a, int count)
{
	int	num;

	num = (*a)->value;
	while (count - 1 > 0)
	{
		num = num / 3;
		count--;
	}
	return (num % 3);
}

int	ternary_count(t_stack **a, int count)
{
	int		digit[3];
	int		num;
	t_stack	*head;

	digit[0] = 0;
	digit[1] = 0;
	digit[2] = 0;
	head = *a;
	while (head != NULL)
	{
		num = head->value;
		while (count - 1 > 0)
		{
			num = num / 3;
			count--;
		}
		digit[num % 3] = 1;
		head = head->next;
	}
	return (4 * digit[2] + 2 * digit[1] + 1 * digit[0]);
}

void	ternary_radix_sort(t_stack **a, t_stack **b)
{
	int	count;
	int	a_size;
	int	b_size;
	int	i;

	count = 0;
	a_size = ft_stacksize(*a);
	while (!is_sorted(a))
	{
		i = 0;
		while (i < a_size)
		{
			if (ternary_digit(a, count) == 2)
				ra(a, 0);
			else
				pb(a, b);
			i++;
		}
		b_size = ft_stacksize(*b);
		i = 0;
		while (i < b_size)
		{
			if (ternary_digit(b, count) == 1)
				pa(a, b);
			else
				rb(b, 0);
			i++;
		}
		while (ft_stacksize(*b) > 0)
			pa(a, b);
		count++;
	}
}
