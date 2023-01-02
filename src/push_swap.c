#include "../include/push_swap.h"

static void print_stack(t_stack *stack)
{
	t_stack *node;

	node = stack;
	while (node != NULL)
	{
		printf("%d, ", node->value);
		node = node->next;
	}
}

void print_testcase(int argc, char **argv)
{
	int i;

	i = 1;
	printf("\ntestcase: ");
	while (i < argc)
		printf("%s ",argv[i++]);
	printf("\n");
}

// int	compare_value(t_stack **stack,int i,int j)
// {
// 	t_stack	*last;
// 	t_stack *tmp;
// 	int		count;

// 	count = 0;

// 	while (count < i - 1)
// 	{
// 		stack = stack->next;
// 		count++;
// 	}
// 	last = stack;
// 	stack = stack->next;
// 	count++;
// 	tmp = stack;
// 	while (count < j)
// 	{
// 		stack = stack->next;
// 		count++;
// 	}
// 	if (tmp->value > stack->value)
// 		return (1)
// 	else
// 		return (0)

// }

// t_stack	ft_bubble_sort(t_stack **stack)
// {
// 	t_stack	*ret;
// 	int		size;
// 	int		i;
// 	int		j;

// 	size = ft_stacksize(*stack);
// 	i = 1;
// 	while (i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (compare_value(stack, i, j))
// 				change_value(stack, i, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// TODO:make sort

// int	insert_index(t_stack **b, int a_top, int b_size)
// {
// 	t_stack	*front;
// 	t_stack *back;
// 	t_stack	*last;
// 	int	i;

// 	i = 0;
// 	front = *b;
// 	last = ft_stacklast(b);
// 	if (front->value > a_top && a_top > last->value || front->value < a_top && a_top < last->value)
// 		return (i);
// 	while (i < b_size)
// 	{
// 		back = front->next;
// 		if (front->value > a_top && a_top > back->value || front->value < a_top && a_top < back->value)
// 			return(i);
// 		i++;
// 		front = front->next;
// 	}
// 	return (b_size + 1);
// }

// void	ft_sort_medium(t_stack **a, t_stack **b)
// {
// 	int	index;
// 	int	b_size;

// 	while (ft_stacksize(a) > 0)
// 	{
// 		b_size = ft_stacksize(b);
// 		if (b_size <= 1)
// 			pb(a, b);
// 		else
// 		{
// 			index = insert_index(b, a->value, b_size);
// 			//TODO : ft_move_min(b_size, index, a, b);->bを回すversionを作らないといけない
// 		}
// 	}
// }

void	push_swap(int argc, t_stack **a, t_stack **b)
{
	if (argc - 1 == 2)
		ft_sort_two(a);
	if (argc - 1 == 3)
	 	ft_sort_three(a); 
	if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_six_or_less(a, b);
	// else
	// 	ft_sort_medium(a, b);
}
//解放
void ft_stackfree(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	print_testcase(argc, argv);//delete
	//error handling
	judge_input(argc, argv);
	//make a
	input_to_stack(&a, argc, argv);
	//check_stack(&a, argc - 1);
	//make b
	t_stack *b;
	b = NULL;
	//sort
	push_swap(argc, &a, &b);

	//-test-
	printf("a : ");print_stack(a);printf("\n");
	printf("b : ");print_stack(b);printf("\n");

	// ft_stackfree(&a);
	// ft_stackfree(&b);
	//system("leaks push_swap");
	return (0);
}