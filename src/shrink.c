/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:06:12 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/27 12:06:14 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*coordinate_compression(int size, char **argv)
{
	int	*array;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	array = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		array[i] = ft_atoi_ex(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
//TODO: 名前考える
int	shrink_number(int *array, int size, int nbr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == nbr)
			return (i + 1);
		i++;
	}
	return (i + 1);
}
