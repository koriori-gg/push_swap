#include "../include/push_swap.h"

void	ra(t_stack **stack, int flg)
{
	int	size;
	t_stack *tmp;
	
	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (!flg)
		write(1,"ra\n",3);
}

void	rb(t_stack **stack, int flg)
{
	int	size;
	t_stack *tmp;
	
	size = ft_stacksize(*stack);
	if (size <= 1)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_stackadd_back(stack, tmp);
	if (!flg)
		write(1,"rb\n",3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(&*stack_a, 1);
	rb(&*stack_b, 1);
	write(1,"rr\n",3);
}