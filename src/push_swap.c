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
	printf("\nnum : %d,%d\n", num[0], num[1]);
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
		while (index - 1 > 0)//上に押し上げる
		{
			ra(a, 0);
			index--;
		}
	}

	else
	{
		// printf("index -in %d \n", index);
		while (size - index + 1 > 0)//したから
		{
			// printf("size : %d index : %d \n", size, index);
			rra(a, 0);
			index++;
		}		
	}
	pb(a, b);
	// printf("------------\n");
}

void	ft_sort_six_or_less(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	size = ft_stacksize(*a);
	i = 0;
	while (size - i > 3)
	{
		// printf("index : %d\n",ft_min_index(a));
		//ft_min_stack();<-いらんかも
		ft_move_min(size - i, ft_min_index(a), a, b);//<-indexわかったらそれをpbしていく
		i++;
		// printf("a : ");print_stack(*a);printf("\n");
		// printf("b : ");print_stack(*b);printf("\n");
	}
	//printf("a : ");print_stack(*a);printf("\n");
	ft_sort_three(a);//a
	//pa pa pa
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	print_testcase(argc, argv);//delete
	judge_input(argc, argv);
	//make a
	i = 1;
	while (i < argc)
	{
		if (i == 1)
			a = ft_stacknew(ft_atoi_ex(argv[i]));
		else
			ft_stackadd_back(&a, ft_stacknew(ft_atoi_ex(argv[i])));
	//TODO: mallocできなかった時のerror処理 -> stacknew内で出来てるから大丈夫
		i++;
	}
	//TODO: make b
	//make b
	t_stack *b;
	b = ft_stacknew(0);
	//sort
	//ft_sort();
	if (argc - 1 == 2)
		ft_sort_two(&a);
	if (argc - 1 == 3)
	 	ft_sort_three(&a); 
	if (4 <= argc - 1 && argc - 1 <= 6)
		ft_sort_six_or_less(&a, &b);
	//-簡単なリストを作成-
	// t_stack *head;
	// head = ft_stacknew(1);
	// ft_stackadd_back(&head, ft_stacknew(2));
	// ft_stackadd_back(&head, ft_stacknew(3));
	// ft_stackadd_back(&head, ft_stacknew(4));
	//-----------------
	//rrr(&stack, &head);
	//-test-
	printf("a : ");print_stack(a);printf("\n");
	// printf("b : ");print_stack(b);printf("\n");
	return (0);

}