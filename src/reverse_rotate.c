#include "../include/push_swap.h"

void	rra(t_stack **stack, int flg)
{
	int		size;
	int		i;
	t_stack	*first;
	t_stack	*last;
	
	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	first = *stack;
	i = 1;
	while (i < size - 1)
	{
		*stack = (*stack)->next;
		i++;
	}
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	(*stack)->next = first;
	if (!flg)
		write(1,"rra\n",4);	
}

void	rrb(t_stack **stack, int flg)
{
	int		size;
	int		i;
	t_stack	*first;
	t_stack	*last;
	
	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	first = *stack;
	i = 1;
	while (i < size - 1)
	{
		*stack = (*stack)->next;
		i++;
	}
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	(*stack)->next = first;
	if (!flg)
		write(1,"rrb\n",4);	
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(&*stack_a, 1);
	rrb(&*stack_b, 1);	
	write(1,"rr\n",3);
}
