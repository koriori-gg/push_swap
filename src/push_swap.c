/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:00:23 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 17:59:47 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(int argc, t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	if (argc - 1 == 2)
		ft_sort_two(a);
	else if (argc - 1 == 3)
		ft_sort_three(a);
	else if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_four_to_six(a, b);
	else
		ternary_radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	valid_input(argc, argv);
	input_to_stack(&a, argc, argv);
	b = NULL;
	push_swap(argc, &a, &b);
	ft_stackfree(&a);
	ft_stackfree(&b);
	return (0);
}
