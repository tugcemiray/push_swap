/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:45:05 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/15 19:45:06 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack	*stack)
{
	t_stack	*highest;

	if (!stack)
		return (NULL);
	highest = stack;
	while (stack)
	{
		if (stack->nbr > highest->nbr)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_stack	*get_target_in_b(t_stack	*current_a, t_stack	*stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		clst_smllr;

	current_b = stack_b;
	target = NULL;
	clst_smllr = INT_MIN;
	while (current_b)
	{
		if (current_a->nbr > current_b->nbr)
		{
			if (current_a->nbr > current_b->nbr && current_b->nbr > clst_smllr)
			{
				clst_smllr = current_b->nbr;
				target = current_b;
			}
		}
		current_b = current_b->next;
	}
	if (!target)
		target = find_biggest(stack_b);
	return (target);
}

void	target_in_b(t_stack	*stack_a, t_stack	*stack_b)
{
	t_stack	*current_a;

	current_a = stack_a;
	while (current_a)
	{
		current_a->target_node = get_target_in_b(current_a, stack_b);
		current_a = current_a->next;
	}
}
