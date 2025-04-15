/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:41:38 by ubuntu            #+#    #+#             */
/*   Updated: 2025/04/15 03:41:38 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	is_sorted(t_stack	*stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	is_double(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*cmp;

	tmp = stack;
	while (tmp)
	{
		cmp = tmp->next;
		while (cmp)
		{
			if (tmp->nbr == cmp->nbr)
				return (1);
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
