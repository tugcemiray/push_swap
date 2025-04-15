/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:45:10 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/15 21:00:37 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack	*stack)
{
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->nbr < smallest->nbr)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*get_target_in_a(t_stack	*stack_a, t_stack	*current_b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		closest_bigger;

	current_a = stack_a;
	target = NULL;
	closest_bigger = INT_MAX;
	while (current_a)
	{
		if (current_b->nbr < current_a->nbr)
		{
			if (current_a->nbr < closest_bigger)
			{
				closest_bigger = current_a->nbr;
				target = current_a;
			}
		}
		current_a = current_a->next;
	}
	if (!target)
		target = find_smallest(stack_a);
	return (target);
}

void	target_in_a(t_stack	*stack_a, t_stack	*stack_b)
{
	t_stack	*current_b;

	current_b = stack_b;
	while (current_b)
	{
		current_b->target_node = get_target_in_a(stack_a, current_b);
		current_b = current_b->next;
	}
}
