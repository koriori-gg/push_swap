#include "../include/push_swap.h"

void	insert_number(t_stack **a, t_stack **b, int index)
{
	int	b_size;

	b_size = ft_stacksize(*b);
	// printf("bsize %d, index %d\n", b_size, index);
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
	// printf("des\n");
	while (pre != NULL)
	{
		// printf("a_top %d: pre %d: cur %d\n", a_top, pre->value, cur->value);
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
	int		index;
	int		b_max;
	pre = ft_stacklast(*b);
	cur = *b;
	index = 0;
	b_max = search_max(b);
	// printf("asc\n");
	while (pre != NULL)
	{
		// printf("a_top %d: pre %d: cur %d\n", a_top, pre->value, cur->value);
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
	insert_number(a, b, index);
}

// static void print_stack2(t_stack *stack)
// {
// 	t_stack *node;

// 	node = stack;
// 	while (node != NULL)
// 	{
// 		printf("%d, ", node->value);
// 		node = node->next;
// 	}
// }
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
	t_stack	*pre;
	t_stack	*cur;
	int	index;
	int	size;

	pre = *b;
	cur = pre->next;
	size = ft_stacksize(*b);
	if (judge_order(b, search_max(b), search_min(b)))
		index = ;
	else
		index = ;
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
		cur = cur->value;
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
	// printf("a : ");print_stack2(*a);printf("\n");
	// printf("b : ");print_stack2(*b);printf("\n");
	while (size > 0)
	{
		if (judge_order(b, search_max(b), search_min(b)))
			descending_insert(a, b, (*a)->value);
		else
			ascending_insert(a, b, (*a)->value);
		size--;
		// printf("a : ");print_stack2(*a);printf("\n");
		// printf("b : ");print_stack2(*b);printf("\n");
	}
	//b->a
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