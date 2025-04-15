/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tukaraca <tukaraca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:44:14 by tukaraca          #+#    #+#             */
/*   Updated: 2025/04/15 19:47:09 by tukaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!((*str >= 9 && *str <= 13) || *str == 32))
			return (0);
		str++;
	}
	return (1);
}

int	is_same(char *input, char *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_atoi(input) == 0 && ft_atoi(check) == 0)
		return (1);
	if ((input[0] == '-' && check[0] != '-')
		|| (input[0] != '-' && check[0] == '-'))
		return (0);
	if (input[i] == '-' || input[i] == '+')
		i++;
	if (check[j] == '-' || check[j] == '+')
		j++;
	while (input[i] == '0')
		i++;
	while (check[j] == '0')
		j++;
	while (input[i] && check[j])
	{
		if (input[i++] != check[j++])
			return (0);
	}
	return (input[i] == '\0' && check[j] == '\0');
}

static int	nbr_check(char *str, int num)
{
	char	*check;
	int		result;

	check = ft_itoa(num);
	if (!check)
		return (0);
	result = is_same(str, check);
	free(check);
	return (result);
}

int	is_in_limit(char **argv)
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!nbr_check(split[j], ft_atoi(split[j])))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
