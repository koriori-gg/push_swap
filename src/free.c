/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:01:22 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/31 12:00:15 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stackfree(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

/*
void print_stack(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node != NULL)
	{
		printf("%d, ", node->value);
		node = node->next;
	}
}

void	print_testcase(int argc, char **argv)
{
	int	i;

	i = 1;
	printf("\ntestcase: ");
	while (i < argc)
		printf("%s ",argv[i++]);
	printf("\n");
}
*/