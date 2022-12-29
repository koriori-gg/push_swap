#include "../include/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	t_stack *tmp;

	size = ft_stacksize(*stack_b);
	if (size <= 0)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_stackadd_front(stack_a, tmp);
	write(1,"pa\n",3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	t_stack *tmp;

	size = ft_stacksize(*stack_a);
	if (size <= 0)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_stackadd_front(stack_b, tmp);
	write(1,"pb\n",3);
}