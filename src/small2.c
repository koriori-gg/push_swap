#include "../include/push_swap.h"
//sort b
void	ft_sort_two_reverse(t_stack **stack)
{
	t_stack	*head;
	int	num[2];
	int	i;

	head = *stack;
	i = 0;
	while (head != NULL)
	{
		num[i] = head->value;
		head = head->next;
		i++;
	}
	if (num[0] < num[1])
		rrb(stack, 0);
}

void	ft_sort_three_reverse(t_stack **stack)
{
	t_stack	*head;
	int	num[3];
	int	i;

	head = *stack;
	i = 0;
	while (head != NULL)
	{
		num[i] = head->value;
		head = head->next;
		i++;
	}
	if (num[0] < num[1] && num[1] < num[2] && num[0] < num[2])
	{
		rb(stack, 0);
		sb(stack, 0);
	}
	if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
		rb(stack, 0);
	if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		rrb(stack, 0);
	if (num[0] < num[1] && num[1] > num[2] && num[0] > num[2])
		sb(stack, 0);
	if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
	{
		sb(stack, 0);
		rb(stack, 0);
	}
}

void	ft_move_min(int size, int border, t_stack **a, t_stack **b)
{
	t_stack	*top;
	int	count;

	top = *a;
	count = 0;
	while(count < size)
	{
		if (top->value <= border)
			break;
		top = top->next;
		count++;	
	}
	if (count > size / 2)
	{
		while (size - count > 0)
		{
			rra(a, 0);
			count++;
		}
	}
	else
	{
		while (count > 0)
		{
			ra(a, 0);
			count--;
		}
	}
	pb(a, b);
}

void	ft_sort_six_or_less(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	size = ft_stacksize(*a);
	i = 0;
	while (size - i > 3)
	{
		ft_move_min(size - i, size - 3, a, b);
		i++;
	}
	ft_sort_three(a);
	if (ft_stacksize(*b) == 3)
		ft_sort_three_reverse(b);
	else if (ft_stacksize(*b) == 2)
		ft_sort_two_reverse(b);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}