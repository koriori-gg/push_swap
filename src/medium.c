#include "../include/push_swap.h"

void	insert_number(t_stack **a, t_stack **b, int index)
{
	int	b_size;

	b_size = ft_stacksize(*b);
	if (index <= (b_size + 1) / 2)
	{
		while (index > 0)
		{
			rb(b, 0);
			index--;
		}
	}
	else
	{
		while (b_size - index > 0)
		{
			rrb(b, 0);
			index++;
		}
	}
	pb(a,b);
	
}
//降順　654321
void	descending_insert(t_stack **a, t_stack **b, int a_top)
{
	t_stack	*pre;
	t_stack	*cur;
	int		i;
	int		b_max;

	pre = ft_stacklast(*b);
	cur = *b;
	i = 0;
	b_max = search_max(b);
	while (pre != NULL)
	{
		if (pre->value > a_top && a_top > cur->value)
			break;
		else if (cur->value == b_max && pre->value < a_top && a_top > cur->value)
			break;
		else if (cur->value == b_max && pre->value > a_top && a_top < cur->value)
			break;
		pre = cur;
		cur = cur->next;
		i++;
	}
	insert_number(a, b, i);
}
//昇順 123456
void	ascending_insert(t_stack **a, t_stack **b, int a_top)
{
	t_stack	*pre;
	t_stack	*cur;
	int		i;
	int		b_max;
	pre = ft_stacklast(*b);
	cur = *b;
	i = 0;
	b_max = search_max(b);
	while (pre != NULL)
	{
		if (pre->value < a_top && a_top < cur->value)
			break;
		else if (pre->value == b_max && pre->value < a_top && a_top > cur->value)
			break;
		else if (pre->value == b_max && pre->value > a_top && a_top < cur->value)
			break;
		pre = cur;
		cur = cur->next;
		i++;
	}
	insert_number(a, b, i);
}

void	insert_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	int	max;

	i = 0;
	max = search_max(a);
	while (i < 3)
	{
		pb(a, b);
		i++;
	}
	size = ft_stacksize(*a);
	while (size > 0)
	{
		if (judge_order(b, search_max(b), search_min(b)))
			descending_insert(a, b, (*a)->value);
		else
			ascending_insert(a, b, (*a)->value);
		size--;
	}
	while ((*b)->value != max)
		rrb(b,0);
	while (ft_stacksize(*b) != 0)
		pa(a, b);
}