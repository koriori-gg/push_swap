#include "../include/push_swap.h"

void	sa(t_stack **stack, int flg)
{
	int	size;
	t_stack *tmp;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (!flg)
		write(1,"sa\n",3);
}

void	sb(t_stack **stack, int flg)
{
	int	size;
	t_stack *tmp;

	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (!flg)
		write(1,"sb\n",3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(&*stack_a, 1);
	sb(&*stack_b, 1);
	write(1,"ss\n",3);
}
