/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:50:11 by ubuntu            #+#    #+#             */
/*   Updated: 2025/04/15 03:50:11 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack	**stack_a, t_stack	**stack_b)
{
	while (list_size(*stack_a) > 3)
	{
		get_index(*stack_a);
		get_index(*stack_b);
		target_in_b(*stack_a, *stack_b);
		get_cost(*stack_a, *stack_b);
		cheapest_move_to_b(stack_a, stack_b);
	}
}

void	push_to_a(t_stack	**stack_a, t_stack	**stack_b)
{
	while (*stack_b)
	{
		get_index(*stack_a);
		get_index(*stack_b);
		target_in_a(*stack_a, *stack_b);
		take_to_high(stack_a, (*stack_b)->target_node, 'a');
		pa(stack_a, stack_b);
	}	
}

void	push_swap(t_stack	**stack_a, t_stack	**stack_b)
{
	if (list_size(*stack_a) == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
		return ;
	}
	if (list_size(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	push_to_b(stack_a, stack_b);
	if (list_size(*stack_a) == 3)
		sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	last_rotate(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!initialize_stacks(&stack_a, argv))
		return (1);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
