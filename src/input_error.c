/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:00:58 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/27 12:00:59 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	overflow_int(long num, const char *nptr, size_t i, int sign)
{
	long	n;

	n = nptr[i] - 48;
	if (sign == -1 && sign * num > (INT_MAX - n) / 10)
		return (-1);
	if (sign == 1 && sign * num < (INT_MIN + n) / 10)
		return (0);
	else
		return (1);
}

int	ft_atoi_ex(const char *nptr)
{
	size_t	i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = -1;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		sign = sign * (44 - nptr[i]);
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		if (overflow_int(num, nptr, i, sign) != 1)
			return (overflow_int(num, nptr, i, sign));
		num = num * 10 - (nptr[i] - 48);
		i++;
	}
	return (sign * num);
}

void	error()
{
	write(1, "error\n", 6);
	exit(1);
}

static int	ft_isnumber(char *argv_i)
{
	int	j;

	j = 0;
	if (argv_i[j] == '-' || argv_i[j] == '+')
		j++;
	while (argv_i[j])
	{
		if (!ft_isdigit(argv_i[j]))
			return (1);
		j++;
	}
	return (0);
}

void	judge_input(int argc, char **argv)
{
	int		i;
	int		nbr;

	if (argc <= 1)
		error();
	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]))
			error();
		nbr = ft_atoi_ex(argv[i]);
		if ((nbr == -1 || nbr == 0) && ft_strlen(argv[i]) > 2)
			error();
		i++;
	}
}
/*
int	main(void)
{
	printf("min      %d\n",ft_atoi_ex("-2147483648"));
	printf("min - 1  %d\n",ft_atoi_ex("-2147483649"));
	printf("min - 2  %d\n",ft_atoi_ex("-2147483650"));
	printf("min - 3  %d\n",ft_atoi_ex("-2147483651"));
	printf("max      %d\n",ft_atoi_ex("2147483647"));
	printf("max + 1  %d\n",ft_atoi_ex("2147483648"));
	printf("max + 2  %d\n",ft_atoi_ex("2147483649"));
	printf("max + 3  %d\n",ft_atoi_ex("2147483650"));
}
*/