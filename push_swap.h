/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:52:05 by ubuntu            #+#    #+#             */
/*   Updated: 2025/04/14 21:52:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack	**stack);
void	ra(t_stack	**stack_a);
void	rb(t_stack	**stack_b);
void	rr(t_stack	**stack_a, t_stack	**stack_b);
void	reverse_rotate(t_stack	**stack);
void	rra(t_stack	**stack_a);
void	rrb(t_stack	**stack_b);
void	rrr(t_stack	**stack_a, t_stack	**stack_b);
void	push(t_stack	**from, t_stack	**to);
void	pa(t_stack	**stack_a, t_stack	**stack_b);
void	pb(t_stack	**stack_a, t_stack	**stack_b);

t_stack	*find_biggest(t_stack	*stack);
t_stack	*get_target_in_b(t_stack	*current_a, t_stack	*stack_b);
void	target_in_b(t_stack	*stack_a, t_stack	*stack_b);

t_stack	*find_smallest(t_stack	*stack);
t_stack	*get_target_in_a(t_stack	*stack_a, t_stack	*current_b);
void	target_in_a(t_stack	*stack_a, t_stack	*stack_b);

void	get_cost(t_stack	*stack_a, t_stack	*stack_b);
t_stack	*get_cheapest(t_stack	*stack_a);
void	take_to_high(t_stack	**stack, t_stack	*node, char stack_name);
void	cheapest_move_to_b(t_stack	**stack_a, t_stack	**stack_b);
void	take_min_top(t_stack	**stack_a);
void	last_rotate(t_stack **stack_a);

int		list_size(t_stack	*stack);
void	get_index(t_stack	*stack);
void	sort_three(t_stack	**stack);

int		initialize_stacks(t_stack **stack_a, char **argv);
int		fill_stack(t_stack	**stack, char **argv);

int		is_sorted(t_stack	*stack);
void	free_split(char **split);
void	free_stack(t_stack **stack);
int		is_double(t_stack *stack);
int		is_space(char *str);
int		is_same(char *input, char *check);
int		is_in_limit(char **argv);
#endif