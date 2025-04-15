/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:44:26 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/15 19:44:28 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stack	*stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	get_index(t_stack	*stack)
{
	int	i;
	int	median;

	i = 0;
	median = list_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	sort_three(t_stack	**stack)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*stack);
	if (biggest_node == *stack)
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

void	take_min_top(t_stack	**stack_a)
{
	t_stack	*min;

	min = find_smallest(*stack_a);
	take_to_high(stack_a, min, 'a');
}

void	last_rotate(t_stack **stack_a)
{
	get_index(*stack_a);
	take_min_top(stack_a);
}
