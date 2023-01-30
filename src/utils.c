/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:01:22 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 10:37:37 by ihashimo         ###   ########.fr       */
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

int	is_sorted(t_stack **stack)
{
	t_stack	*pre;
	t_stack	*cur;

	pre = *stack;
	cur = pre->next;
	while (cur != NULL)
	{
		if (pre->value > cur->value)
			return (0);
		pre = pre->next;
		cur = cur->next;
	}
	return (1);
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