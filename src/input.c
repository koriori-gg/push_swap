/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:05:31 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 12:59:55 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	input_to_stack(t_stack **a, int argc, char **argv)
{
	int	i;
	int	*array;
	int	num;

	array = coordinate_compression(argc - 1, argv);
	double_check(array, argc - 1);
	i = 1;
	while (i < argc)
	{
		num = shrink_number(array, argc - 1, ft_atoi_ex(argv[i]));
		if (i == 1)
			*a = ft_stacknew(num);
		else
			ft_stackadd_back(a, ft_stacknew(num));
		i++;
	}
	free(array);
}

void	double_check(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				free(array);
				error();
			}
			j++;
		}
		i++;
	}
}
