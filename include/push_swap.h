/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihashimo <maaacha.kuri05@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:56:46 by ihashimo          #+#    #+#             */
/*   Updated: 2023/01/30 14:36:33 by ihashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

//連結リスト
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

//swap
void	sa(t_stack **stack, int flg);
void	sb(t_stack **stack, int flg);
void	ss(t_stack **stack_a, t_stack **stack_b);
//push
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
//rotate
void	ra(t_stack **stack, int flg);
void	rb(t_stack **stack, int flg);
void	rr(t_stack **stack_a, t_stack **stack_b);
//reverse_rotote
void	rra(t_stack **stack, int flg);
void	rrb(t_stack **stack, int flg);
void	rrr(t_stack **stack_a, t_stack **stack_b);
//valid
void	error(void);
int		ft_atoi_ex(const char *nptr);
void	valid_input(int argc, char **argv);
//stack
t_stack	*ft_stacknew(int value);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
//small
void	ft_sort_two(t_stack **stack);
void	ft_sort_three(t_stack **stack);
int		ft_min_index(t_stack **stack);
void	ft_move_min(int size, int index, t_stack **a, t_stack **b);
void	ft_sort_four_to_six(t_stack **a, t_stack **b);
//shrink
int		*coordinate_compression(int size, char **argv);
int		shrink_number(int *array, int size, int nbr);
//input
void	input_to_stack(t_stack **a, int argc, char **argv);
void	double_check(int *array, int size);
//utils
int		is_sorted(t_stack **stack);
void	ft_stackfree(t_stack **stack);
//radix
void	ternary_radix_sort(t_stack **a, t_stack **b);
//ternary
int		ternary_digit(t_stack **a, int count);
int		is_ternary(t_stack **a, int count);
//print
// void 	print_stack(t_stack *stack);
// void	print_testcase(int argc, char **argv);
#endif