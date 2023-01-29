#include "../include/push_swap.h"

void	quick_sort(t_stack **a, t_stack**b)
{
	int	size;
	int	count;

	size = ft_stacksize(*a);
	count = 0;
	while (count < size)
	{
		if ((*a)->value < size / 2)
				pb(a, b);
			else
				ra(a, 0);
			count++;
	}
	
}