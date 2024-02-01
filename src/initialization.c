/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:41:34 by sade              #+#    #+#             */
/*   Updated: 2024/02/01 10:19:32 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*make_new(int nbr)
{
	t_stack	*stack_a;

	stack_a = stack_new(nbr);
	if (!stack_a)
	{
		free_stack(&stack_a);
		return (0);
	}
	return (stack_a);
}

t_stack	*append_stack(t_stack *stack_a, int nbr)
{
	int	fail;

	fail = add_stack_last(&stack_a, stack_new((int)nbr));
	if (fail)
	{
		free_stack(&stack_a);
		return (0);
	}
	return (stack_a);
}

t_stack	*fill_stack_one(int argc, char **args)
{
	long		nbr;
	t_stack		*stack_a;
	int			i;

	stack_a = NULL;
	i = 1;
	nbr = 0;
	while (args[i] != NULL)
		i++;
	argc = i;
	arg_check(args);
	i = 0;
	while (i < argc)
	{
		nbr = ft_atoi(args[i]);
		if (i == 0)
			stack_a = make_new(nbr);
		else
			append_stack(stack_a, nbr);
		i++;
	}
	return (stack_a);
}

t_stack	*fill_stack(int argc, char **argv)
{
	long	nbr;
	t_stack	*stack_a;
	int		i;
	char	**args;

	stack_a = NULL;
	i = 0;
	nbr = 0;
	args = argv;
	arg_check(args);
	while (i < argc)
	{
		nbr = ft_atoi(args[i]);
		if (i == 0)
			stack_a = make_new(nbr);
		else
			append_stack(stack_a, nbr);
		i++;
	}
	return (stack_a);
}

void	assign_idx(t_stack *stack_a, int size)
{
	t_stack	*highest;
	t_stack	*ptr;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
