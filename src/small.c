#include "../include/push_swap.h"

void	ft_sort_two(t_stack **stack)
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
	if (num[0] > num[1])
		rra(stack, 0);
}

void	ft_sort_three(t_stack **stack)
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
	if (num[0] > num[1] && num[1] < num[2] && num[0] <= num[2])
		sa(stack, 0);
	if (num[0] > num[1] && num[1] <= num[2] && num[0] > num[2])
		ra(stack, 0);
	if (num[0] <= num[1] && num[1] > num[2] && num[0] >= num[2])
		rra(stack, 0);
	if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
	{
		ra(stack, 0);
		sa(stack, 0);
	}
	if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
	{
		rra(stack, 0);
		sa(stack, 0);
	}
}

int	ft_min_index(t_stack **stack)
{
	t_stack*	head;
	long	min;
	int		index;
	int		i;

	head = *stack;
	min = head->value;
	index = 1;//1 or 0 sizeにあわせるなら1で良さげ
	i = 1;
	while (head != NULL)
	{
		if (min > head->value)
		{
			min = head->value;
			index = i;
		}
		head = head->next;
		i++;
	}
	return (index);
}

void	ft_move_min(int size, int index, t_stack **a, t_stack **b)
{
	if (index <= (size + 1) / 2)
	{
		while (index - 1 > 0)
		{
			ra(a, 0);
			index--;
		}
	}
	else
	{
		while (size - index + 1 > 0)
		{
			rra(a, 0);
			index++;
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
		ft_move_min(size - i, ft_min_index(a), a, b);
		i++;
	}
	ft_sort_three(a);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}