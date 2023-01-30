/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:06:49 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/29 19:34:20 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	binary_radix_sort(t_stack **a, t_stack **b)
{
	int	num;
	int	size;
	int	count;

	num = 0;
	size = ft_stacksize(*a);
	while (!is_sorted(a))
	{
		count = 0;
		while (count < size)
		{
			if (((*a)->value >> num & 1) == 0)
				pb(a, b);
			else
				ra(a, 0);
			count++;
		}
		while (ft_stacksize(*b) > 0)
			pa(a, b);
		num++;
	}
}
