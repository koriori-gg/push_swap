/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:07:32 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/27 12:07:33 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stacknew(int value)
{
	t_stack	*ret;

	ret = ft_calloc(1, sizeof(t_stack));
	if (!ret)
		return (NULL);
	ret->value = value;
	ret->next = NULL;
	return (ret);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int		size;

	size = 0;
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size + 1);
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*ptr;

	if (!*stack)
		*stack = new;
	else
	{
		ptr = ft_stacklast(*stack);
		ptr->next = new;
	}
}
