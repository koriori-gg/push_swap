/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:34:35 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 12:21:15 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_atob(t_stack **a, t_stack **b, int count)
{
	int	a_size;
	int	i;

	a_size = ft_stacksize(*a);
	i = 0;
	while (i < a_size)
	{
		if (ternary_digit(a, count) == 2)
			ra(a, 0);
		else
			pb(a, b);
		i++;
	}
}

static void	ternary_sort(t_stack **a, t_stack **b, int count)
{
	int	b_size;
	int	i;

	push_atob(a, b, count);
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
}

static void	binary_sort(t_stack **a, t_stack **b, int count)
{
	int	a_size;
	int	i;

	a_size = ft_stacksize(*a);
	i = 0;
	while (i < a_size)
	{
		if (is_sorted(a))
			break ;
		if (ternary_digit(a, count) != 0)
			ra(a, 0);
		else
			pb(a, b);
		i++;
	}
	while (ft_stacksize(*b) > 0)
		pa(a, b);
}

void	ternary_radix_sort(t_stack **a, t_stack **b)
{
	int	count;

	count = 1;
	while (!is_sorted(a))
	{
		if (is_ternary(a, count))
			ternary_sort(a, b, count);
		else
			binary_sort(a, b, count);
		count++;
	}
}
