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

void	print_testcase(int argc, char **argv)
{
	int i;

	i = 1;
	printf("\ntestcase: ");
	while (i < argc)
		printf("%s ",argv[i++]);
	printf("\n");
}

void	push_swap(int argc, t_stack **a, t_stack **b)
{
	if (argc - 1 == 2)
		ft_sort_two(a);
	else if (argc - 1 == 3)
	 	ft_sort_three(a); 
	else if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_six_or_less(a, b);
	else
	 	insert_sort(a,b);
	//TODO: 名前変更
		
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
	t_stack *b;
	print_testcase(argc, argv);//delete
	//error handling
	judge_input(argc, argv);
	//make a
	input_to_stack(&a, argc, argv);
	//check_stack(&a, argc - 1);
	//make b
	b = NULL;
	//sort
	// int flg = judge_order(&a, search_max(&a), search_min(&a));
	// if (flg)
	// 	printf("koujyun %d\n",flg);
	// else
	// 	printf("syoujyun\n");
	push_swap(argc, &a, &b);

	//-test-
	printf("a : ");print_stack(a);printf("\n");
	printf("b : ");print_stack(b);printf("\n");

	// ft_stackfree(&a);
	// ft_stackfree(&b);
	//system("leaks push_swap");
	return (0);
}