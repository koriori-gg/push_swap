/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:19:16 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 12:19:19 by ihashimo         ###   ########.fr       */
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

int	is_ternary(t_stack **a, int count)
{
	int	digit[3];
	int	a_size;

	digit[0] = 0;
	digit[1] = 0;
	digit[2] = 0;
	a_size = ft_stacksize(*a);
	while (a_size > 0)
	{
		digit[ternary_digit(a, count)] += 1;
		a = &(*a)->next;
		a_size--;
	}
	if (digit[0] > 0 && digit[1] > 0 && digit[2] > 0)
		return (1);
	else
		return (0);
}
