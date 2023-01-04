#include "../include/push_swap.h"
//sort a
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
