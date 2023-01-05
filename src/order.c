#include "../include/push_swap.h"

int	search_min(t_stack **stack)
{
	t_stack*	head;
	long		min;

	head = *stack;
	min = head->value;
	while (head != NULL)
	{
		if (min > head->value)
		{
			min = head->value;
		}
		head = head->next;
	}
	return (min);
}

int	search_max(t_stack **stack)
{
	t_stack*	head;
	long		max;

	head = *stack;
	max = head->value;

	while (head != NULL)
	{
		if (max < head->value)
		{
			max = head->value;
		}
		head = head->next;
	}
	return (max);
}
//flg : 1 降順 , 0 昇順
int	judge_order(t_stack **stack, int max, int min)
{
	t_stack	*pre;
	t_stack	*cur;
	t_stack	*nex;

	pre = ft_stacklast(*stack);
	cur = *stack;
	nex = cur ->next;
	while (nex != NULL)
	{
		// printf("judge_order pre:%d cur:%d nex:%d\n",pre->value, cur->value, nex->value);
		if (cur->value != max && cur->value != min)
		{
			if (pre->value < cur->value && cur->value < nex->value)
				return (0);
			else if (pre->value > cur->value && cur->value > nex->value)
				return (1);
		}
		pre = cur;
		cur = cur->next;
		nex = nex->next;
	}
	nex = *stack;
	// printf("judge_order pre:%d cur:%d nex:%d\n",pre->value, cur->value, nex->value);
	if (cur->value != max && cur->value != min)
	{
		if (pre->value < cur->value && cur->value < nex->value)
			return (0);
		else if (pre->value > cur->value && cur->value > nex->value)
			return (1);
	}
	// printf("judge_order not");
	return (0);
}


//flg : 1 降順 , 0 昇順
/*
int	judge_order(t_stack **stack)
{
	t_stack	*top;
	int		flg;
	int		min;
	int		now;

	flg = 0;
	min = search_min(stack);
	top = *stack;
	while (*stack != NULL)//TODO:条件式
	{
		if ((*stack)->value == min)
			break;
		*stack = (*stack)->next;
	}
	now = (*stack)->value;
	if ((*stack)->next != NULL)
		*stack = (*stack)->next;
	while ((*stack)->next != NULL)
	{
		if (now < (*stack)->value)
			now = (*stack)->value;
		else
			flg = 1;
		*stack = (*stack)->next;
	}
	while (top->value != min)
	{
		if (now < top->value)
			now = top->value;
		else
			flg = 1;
		top = top->next;
	}
	return (flg);
}*/