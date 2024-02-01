/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:37:16 by sade              #+#    #+#             */
/*   Updated: 2024/02/01 11:26:24 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		do_sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4 || size == 5)
		sort_5(stack_a, stack_b);
	else if (size > 5)
		sort(stack_a, stack_b);
}

t_stack	*fill_split(int argc, char **args)
{
	t_stack	*stack_a;

	if (!args)
		return (0);
	stack_a = fill_stack_one(argc, args);
	if (is_sorted(&stack_a))
	{
		ft_free(args);
		free_stack(&stack_a);
		return (0);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_b = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_a = fill_split(argc, args);
	}
	else
		stack_a = fill_stack(argc - 1, argv + 1);
	assign_idx(stack_a, (stack_size(stack_a) + 1));
	if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	push_swap(&stack_a, &stack_b, stack_size(stack_a));
	ft_free(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
