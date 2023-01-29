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
int	descending_count(t_stack **b, int a_top)
{
	t_stack	*pre;
	t_stack	*cur;
	int		index;
	int		b_max;

	pre = ft_stacklast(*b);
	cur = *b;
	index = 0;
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
		index++;
	}
	return (index);
}
//昇順 123456
int	ascending_count(t_stack **b, int a_top)
{
	t_stack	*pre;
	t_stack	*cur;
	int		index;
	int		b_max;
	pre = ft_stacklast(*b);
	cur = *b;
	index = 0;
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
		index++;
	}
	return (index);
}

void	pre_rotate(t_stack **a, int num)
{
	t_stack	*head;
	int	size;
	int	index;

	head =*a;
	index = 0;
	while (head != NULL && head->value != num)
	{
		head = head->next;
		index++;
	}
	size = ft_stacksize(*a);
	if (index <= (size + 1) / 2)
	{
		while (index > 0)
		{
			ra(a, 0);
			index--;
		}
	}
	else
	{
		while (size - index > 0)
		{
			rra(a, 0);
			index++;
		}
	}
}

int	move_a(t_stack **a, int num)
{
	t_stack	*cur;
	int	index;
	int	size;

	cur = *a;
	index = 0;
	size = ft_stacksize(*a);
	while (cur != NULL && cur->value == num)
	{
		index++;
		cur = cur->next;
	}
	if (index <= (size + 1) / 2)
		return (index);
	else
		return (size - index);
}

int	move_b(t_stack **b, int num)
{
	int	index;
	int	size;

	size = ft_stacksize(*b);
	if (judge_order(b, search_max(b), search_min(b)))
		index = descending_count(b, num);
	else
		index = ascending_count(b, num);
	if (index <= (size + 1) / 2)
		return (index);
	else
		return (size - index);
}

int	search_min_move(t_stack **a, t_stack **b)
{
	t_stack	*cur;
	int	count;
	int	ret;

	count = INT_MAX;
	ret = 0;
	cur = *a;
	while (cur != NULL)
	{
		if (count > move_a(a, cur->value) + move_b(b, cur->value))
			ret = cur->value;
		cur = cur->next;
	}
	return (ret);
}

void	insert_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	int	max;
	int	min;
	i = 0;
	max = search_max(a);
	min = search_min(a);
	while (i < 3)
	{
		pb(a, b);
		i++;
	}
	size = ft_stacksize(*a);
	while (size > 0)
	{
		pre_rotate(a,search_min_move(a, b));
		if (judge_order(b, search_max(b), search_min(b)))
			insert_number(a, b, descending_count(b, (*a)->value));
		else
			insert_number(a, b, ascending_count(b, (*a)->value));
		size--;
	}
	if (judge_order(b, search_max(b), search_min(b)))
	{
		while ((*b)->value != max)
			rb(b,0);
		while (ft_stacksize(*b) != 0)
			pa(a, b);
	}
	else
	{
		while ((*b)->value != min)
		{
			rb(b,0);
		}
		while (ft_stacksize(*b) != 0)
		{
			pa(a, b);
			ra(a, 0);
		}
	}
}